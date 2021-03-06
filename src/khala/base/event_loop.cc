// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <khala/base/cpp_feature.hh>
#include <khala/base/event_loop.hh>

namespace khala::base {

EventLoop::EventLoop() {
  loop_ = new uv_loop_t;
  uv_loop_init(loop_);
}

EventLoop::~EventLoop() {
  if (PREFER_TRUE(loop_ != nullptr)) {
    uv_loop_close(loop_);
    delete loop_;
    loop_ = nullptr;
  }
}

EventLoop::EventLoop(EventLoop&& rhs) noexcept : loop_(rhs.loop_) {
  rhs.loop_ = nullptr;
}

bool EventLoop::Run() noexcept { return uv_run(loop_, UV_RUN_DEFAULT) == 0; }

bool EventLoop::RunOnce() noexcept { return uv_run(loop_, UV_RUN_ONCE) == 0; }

bool EventLoop::RunNoWait() noexcept {
  return uv_run(loop_, UV_RUN_NOWAIT) == 0;
}

bool EventLoop::Alive() const noexcept { return !(uv_loop_alive(loop_) == 0); }

void EventLoop::Stop() { uv_stop(loop_); }

void EventLoop::UpdateTime() { uv_update_time(loop_); }

EventLoop::Time_t EventLoop::Now() const { return Time_t{uv_now(loop_)}; }

}  // namespace khala::base
