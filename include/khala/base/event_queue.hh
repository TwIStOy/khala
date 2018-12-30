// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <glog/logging.h>
#include <khala/base/event_loop.hh>

#include <atomic>
#include <functional>
#include <mutex>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace khala::base {

template<typename... Elem>
class EventQueue {
 public:
  using Rebind_t = EventQueue<Elem...>;
  using Callback_t = std::function<void(Elem...)>;
  static constexpr uint32_t DefaultMaxSize = 1024 * 8;

 public:
  explicit EventQueue(EventLoop* loop, uint32_t max_size = DefaultMaxSize);
  ~EventQueue();

  void SetMaxSize(uint32_t max_size);

  template<typename Func>
  void RegisterCallback(Func&& cb);

  template<typename... Args, typename = typename std::enable_if_t<
                                 (std::is_convertible_v<Args, Elem> && ...)>>
  bool Push(Args&&... elements);

  bool IsEmpty();
  bool IsClosed();

  void Close();

 private:
  using StorageType = std::tuple<Elem...>;

  static void UvAsyncCallback(uv_async_t* handle);

  void TakeAll(std::vector<StorageType>*);

  template<std::size_t... Index>
  void InvokeCallback(StorageType event, std::index_sequence<Index...>);

 private:
  EventLoop* loop_;
  uint32_t max_size_;
  Callback_t callback_;

  std::mutex queue_lock_;
  std::queue<StorageType> queue_;

  std::atomic<bool> closed_ = false;
  uv_async_t async_{};
};

template<typename... Elem>
EventQueue<Elem...>::EventQueue(EventLoop* loop, uint32_t max_size)
    : loop_(loop), max_size_(max_size) {
  uv_async_init(loop->LoopBase(), &async_, &EventQueue::UvAsyncCallback);
}

template<typename... Elem>
void EventQueue<Elem...>::UvAsyncCallback(uv_async_t* handle) {
  auto* self = static_cast<Rebind_t*>(handle->data);

  std::vector<StorageType> events;
  self->TakeAll(&events);

  if (!self->callback_) {
    return;
  }

  for (auto& value : events) {
    self->InvokeCallback(std::move(value),
                         std::make_index_sequence<sizeof...(Elem)>{});
  }
}

template<typename... Elem>
void EventQueue<Elem...>::SetMaxSize(uint32_t max_size) {
  max_size_ = max_size;
}

template<typename... Elem>
template<typename Func>
void EventQueue<Elem...>::RegisterCallback(Func&& cb) {
  callback_ = Callback_t{std::forward<Func>(cb)};
}

template<typename... Elem>
template<typename... Args, typename>
bool EventQueue<Elem...>::Push(Args&&... elements) {
  if (closed_) {
    LOG(WARNING)
        << "You should not push any element after this queue was closed.";
    return false;
  }

  {
    std::unique_lock<std::mutex> lock(queue_lock_);

    if (queue_.size() >= max_size_) {
      LOG(INFO) << "Too many packets in queue: " << queue_.size();
      return false;
    }

    queue_.push(StorageType{std::forward<Args>(elements)...});
  }

  async_.data = this;
  if (int err = uv_async_send(&async_) != 0) {
    LOG(WARNING) << "Failed to push element into uv_async, " << uv_err_name(err)
                 << ", " << uv_strerror(err);
    return false;
  }
  return true;
}

template<typename... Elem>
bool EventQueue<Elem...>::IsEmpty() {
  std::unique_lock<std::mutex> lock(queue_lock_);
  return queue_.empty();
}

template<typename... Elem>
bool EventQueue<Elem...>::IsClosed() {
  std::unique_lock<std::mutex> lock(queue_lock_);
  return queue_ == nullptr;
}

template<typename... Elem>
void EventQueue<Elem...>::Close() {
  std::unique_lock<std::mutex> lock(queue_lock_);
  if (!queue_.empty()) {
    LOG(WARNING)
        << "You should close this queue after taking all the elements.";
  }

  closed_ = true;
  uv_close(reinterpret_cast<uv_handle_t*>(&async_), nullptr);
}

template<typename... Elem>
void EventQueue<Elem...>::TakeAll(std::vector<EventQueue::StorageType>* vec) {
  std::unique_lock<std::mutex> lock(queue_lock_);

  if (closed_) {
    LOG(WARNING) << "This queue has been closed.";
    return;
  }

  while (!queue_.empty()) {
    vec->push_back(std::move(queue_.front()));
    queue_.pop();
  }
}

template<typename... Elem>
EventQueue<Elem...>::~EventQueue() {
  Close();
}

template<typename... Elem>
template<size_t... Index>
void EventQueue<Elem...>::InvokeCallback(EventQueue::StorageType event,
                                         std::index_sequence<Index...>) {
  if (callback_) {
    callback_(std::move(std::get<Index>(event))...);
  }
}

}  // namespace khala::base
