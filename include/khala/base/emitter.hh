// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include <algorithm>
#include <functional>
#include <list>
#include <memory>
#include <type_traits>
#include <vector>

namespace khala::base {

template<typename T>
struct Emitter {
 private:
  struct BaseHandler {
    virtual bool Empty() const noexcept = 0;
    virtual void Clear() noexcept = 0;
    virtual ~BaseHandler() noexcept;
  };

  template<typename Event>
  struct Handler final : BaseHandler {
    using Listener = std::function<void(Event&, T&)>;
    struct Element {
      Element(bool arg1, Listener arg2)
          : to_disable(arg1), listener(std::move(arg2)) {}

      Element(Element const&) = delete;
      Element(Element&&) = default;

      bool to_disable;
      Listener listener;
    };
    using ListenerList = std::list<Listener>;
    using Connection = typename ListenerList::iterator;

    bool Empty() const noexcept final;

    void Clear() noexcept final;

    Connection Once(Listener func);

    Connection On(Listener func);

    void Erase(Connection conn) noexcept;

    void Emit(Event& event, T& t_ref);

   private:
    bool publishing_{false};
    ListenerList once_listeners_{};
    ListenerList on_listeners_{};
  };

  template<typename Event>
  Handler<Event>* GetHandler() noexcept;

 protected:
  template<typename Event>
  void Emit(Event e);

 private:
  static size_t NextId();

  template<typename>
  static size_t EventTypeId();

 public:
  template<typename Event>
  using Listener = typename Handler<Event>::Listener;

  virtual ~Emitter() noexcept;

  template<typename Event>
  struct Connection : private Handler<Event>::Connection {
    template<typename>
    friend class Emitter;

    Connection() = default;
    Connection(const Connection&) = default;
    Connection(Connection&&) = default;

    Connection(typename Handler<Event>::Connection conn)
        : Handler<Event>::Connection{std::move(conn)} {}

    Connection& operator=(const Connection&) = default;
    Connection& operator=(Connection&&) = default;
  };

  template<typename Event>
  Connection<Event> On(Listener<Event> listener);

  template<typename Event>
  Connection<Event> Once(Listener<Event> listener);

  template<typename Event>
  void Erase(Connection<Event> conn) noexcept;

  void Clear();

  template<typename Event>
  void Clear();

  bool Empty();

  template<typename Event>
  bool Empty();

 private:
  std::vector<std::unique_ptr<BaseHandler>> handlers_;
};

template<typename T>
template<typename Event>
bool Emitter<T>::Handler<Event>::Empty() const noexcept {
  auto func = [](auto&& ele) { return ele.to_disable; };
  return std::all_of(once_listeners_.cbegin(), once_listeners_.cend(), func) &&
         std::all_of(on_listeners_.cbegin(), on_listeners_.cend(), func);
}

template<typename T>
template<typename Event>
void Emitter<T>::Handler<Event>::Clear() noexcept {
  if (publishing_) {
    auto func = [](auto&& ele) { ele.to_disable = true; };
    std::for_each(once_listeners_.begin(), once_listeners_.end(), func);
    std::for_each(on_listeners_.begin(), on_listeners_.end(), func);
  } else {
    once_listeners_.clear();
    on_listeners_.clear();
  }
}

template<typename T>
template<typename Event>
typename Emitter<T>::template Handler<Event>::Connection
Emitter<T>::Handler<Event>::Once(Emitter<T>::Handler<Event>::Listener func) {
  once_listeners_.emplace(once_listeners_.cend(), false, std::move(func));
}

template<typename T>
template<typename Event>
typename Emitter<T>::template Handler<Event>::Connection
Emitter<T>::Handler<Event>::On(Emitter<T>::Handler<Event>::Listener func) {
  on_listeners_.emplace(once_listeners_.cend(), false, std::move(func));
}

template<typename T>
template<typename Event>
void Emitter<T>::Handler<Event>::Erase(Connection conn) noexcept {
  conn->to_disable = true;

  if (!publishing_) {
    auto func = [](auto&& ele) { return ele.to_disable; };

    once_listeners_.remove_if(func);
    on_listeners_.remove_if(func);
  }
}

template<typename T>
template<typename Event>
void Emitter<T>::Handler<Event>::Emit(Event& event, T& t_ref) {
  ListenerList curr{};
  once_listeners_.swap(curr);

  auto func = [&event, &t_ref](auto&& ele) {
    if (!ele.to_disable) {
      ele.listener(event, t_ref);
    }
  };

  publishing_ = true;

  std::for_each(on_listeners_.rbegin(), on_listeners_.rend(), func);
  std::for_each(curr.rbegin(), curr.rend(), func);

  publishing_ = false;

  on_listeners_.remove_if([](auto&& element) { return element.first; });
}

template<typename T>
size_t Emitter<T>::NextId() {
  static size_t counter = 0;
  return counter++;
}

template<typename T>
template<typename>
size_t Emitter<T>::EventTypeId() {
  static size_t id = NextId();
  return id;
}

template<typename T>
template<typename Event>
Emitter<T>::Handler<Event>* Emitter<T>::GetHandler() noexcept {
  size_t type = EventTypeId<Event>();

  if (!(type < handlers_.size())) {
    handlers_.resize(type + 1);
  }

  if (!handlers_[type]) {
    handlers_[type] = std::make_unique<Handler<Event>>();
  }

  return handlers_[type].get();
}

template<typename T>
template<typename Event>
void Emitter<T>::Emit(Event e) {
  GetHandler<Event>()->Emit(std::move(e), *this);
}

template<typename T>
Emitter<T>::~Emitter() noexcept {
  static_assert(std::is_base_of_v<Emitter<T>, T>, "FIX IT!!!");
}

template<typename T>
template<typename Event>
Emitter<T>::Connection<Event> Emitter<T>::On(Listener<Event> listener) {
  GetHandler<Event>()->On(std::move(listener));
}

template<typename T>
template<typename Event>
Emitter<T>::Connection<Event> Emitter<T>::Once(Listener<Event> listener) {
  GetHandler<Event>()->Once(std::move(listener));
}

template<typename T>
template<typename Event>
void Emitter<T>::Erase(Emitter<T>::Connection<Event> conn) noexcept {
  GetHandler<Event>()->Erase(std::move(conn));
}

template<typename T>
void Emitter<T>::Clear() {
  for (auto&& handler : handlers_) {
    if (handler) {
      handler->Clear();
    }
  }
}

template<typename T>
template<typename Event>
void Emitter<T>::Clear() {
  GetHandler<Event>()->Clear();
}

template<typename T>
bool Emitter<T>::Empty() {
  for (auto&& handler : handlers_) {
    if (handler) {
      if (!handler->Empty()) {
        return false;
      }
    }
  }
  return true;
}

template<typename T>
template<typename Event>
bool Emitter<T>::Empty() {
  return GetHandler<Event>()->Empty();
}

}  // namespace khala::base

