// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include <algorithm>
#include <functional>
#include <list>
#include <memory>
#include <vector>

namespace khala::base {

template<typename T>
struct Emitter {
 public:
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

    void Publish(Event& event, T& t_ref);

   private:
    bool publishing_{false};
    ListenerList once_listeners_{};
    ListenerList on_listeners_{};
  };

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
void Emitter<T>::Handler<Event>::Publish(Event& event, T& t_ref) {
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

}  // namespace khala::base
