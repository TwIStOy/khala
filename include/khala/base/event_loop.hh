// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

namespace khala::base {

class EventLoop {
 public:
  EventLoop();
  ~EventLoop();

  EventLoop(EventLoop&&) noexcept;

  EventLoop(EventLoop const&) = delete;
  EventLoop& operator=(EventLoop const&) = delete;

  bool Run();
  bool RunOnce();
  bool RunNoWait();

  void Stop();

  void UpdateTime();
  int64_t Now() const;

  inline uv_loop_t* LoopBase() const;

 private:
  uv_loop_t* loop_;
};

inline uv_loop_t* EventLoop::LoopBase() const { return loop_; }

}  // namespace khala::base
