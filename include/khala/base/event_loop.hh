// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include <khala/base/emitter.hh>
#include <khala/base/builtin_events.hh>

#include <chrono>
#include <memory>

namespace khala::base {

class EventLoop final : public Emitter<EventLoop>,
                        public std::enable_shared_from_this<EventLoop> {
 public:
  using Time_t = std::chrono::duration<uint64_t, std::milli>;

  EventLoop();
  ~EventLoop();

  EventLoop(EventLoop&&) noexcept;

  EventLoop(EventLoop const&) = delete;
  EventLoop& operator=(EventLoop const&) = delete;

  bool Run() noexcept;
  bool RunOnce() noexcept;
  bool RunNoWait() noexcept;

  bool Alive() const noexcept;

  void Stop();

  void UpdateTime();
  Time_t Now() const;

  inline uv_loop_t* LoopBase() const;

 private:
  uv_loop_t* loop_;
};

inline uv_loop_t* EventLoop::LoopBase() const { return loop_; }

}  // namespace khala::base
