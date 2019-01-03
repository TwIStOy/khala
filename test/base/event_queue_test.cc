// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/cpp_feature.hh>
#include <khala/base/event_loop.hh>
#include <khala/base/event_queue.hh>

#include <iostream>
#include <string>
#include <thread>

class MoveOnly {
 public:
  MoveOnly() = default;

  ~MoveOnly() = default;

  MoveOnly(MoveOnly&&) = default;
  MoveOnly(MoveOnly const&&) = delete;

  MoveOnly& operator=(MoveOnly&&) = default;
  MoveOnly& operator=(MoveOnly const&) = delete;
};

struct Foo {
  void DoDummy(MAYBE_UNUSED int i, MAYBE_UNUSED std::string str) const {}
};

struct Bar {
  void DoDummy(MAYBE_UNUSED MoveOnly a) const {}
};

TEST(EventQueueTest, Base) {
  using khala::base::EventLoop;
  using khala::base::EventQueue;

  constexpr int kStop = 10 * 1000 * 1000;

  EventLoop loop;

  using QueueType = EventQueue<int, std::string>;

  using MoveQueueType = EventQueue<MoveOnly>;
  MoveQueueType move_queue_(&loop);
  std::function<void(MoveOnly)> cb = [](MoveOnly) {};
  // expect compile well
  move_queue_.RegisterCallback(std::move(cb));

  QueueType q1(&loop);
  // expect compile well
  q1.RegisterCallback([](int, std::string) {});

  EventLoop::Time_t end_time{0};
  auto functor = [&loop, &end_time](int i, std::string s) {
    LOG_EVERY_N(INFO, 10000) << "Got i: " << i << ", s: " << s;
    if (PREFER_FALSE(i == kStop - 1)) {
      end_time = loop.Now();
      loop.Stop();
    }

    ASSERT_EQ(std::to_string(i), s);
  };

  QueueType q2(&loop);
  q2.RegisterCallback(std::ref(functor));

  using std::placeholders::_1;
  using std::placeholders::_2;
  Foo f;
  QueueType q3(&loop);
  q3.SetMaxSize(256);
  // expect compile well
  q3.RegisterCallback(std::bind(&Foo::DoDummy, &f, _1, _2));

  auto t = std::thread([&loop]() { return loop.Run(); });

  auto start = loop.Now();
  for (int i = 0; i < kStop; i++) {
    while (!q2.Push(i, std::to_string(i))) {
      ::usleep(10 * 1000);
    }
  }

  t.join();

  std::cout << "Speed: "
            << kStop / static_cast<double>((end_time - start).count())
            << "k qps" << std::endl;
}
