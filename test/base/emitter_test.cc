// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/emitter.hh>

#include <iostream>

using khala::base::Emitter;

struct Event1 {
  int bar;
};

struct Event2 {
  int bar;
};

struct Foo final : public Emitter<Foo> {
  int foo;

  template<typename E>
  void PublicEmit(E e) {
    Emit<E>(std::move(e));
  }
};

template<typename E>
struct EventCallback {
  EventCallback(int exp1, int exp2)
      : expect_event_value(exp2), expect_object_value(exp1) {}

  void Call(E& ev, Foo& obj) {
    count_++;
    EXPECT_EQ(ev.bar, expect_event_value);
    EXPECT_EQ(obj.foo, expect_object_value);
  }

  Foo::Listener<E> MakeListener() {
    auto self = this;
    return [self](E& ev, Foo& obj) { self->Call(ev, obj); };
  }

  bool ExpectCalled(uint32_t expect) {
    EXPECT_EQ(count_, expect);
    return count_ == expect;
  }

  uint32_t count_{0};
  int expect_event_value;
  int expect_object_value;
};

using Event1Callback = EventCallback<Event1>;
using Event2Callback = EventCallback<Event2>;

TEST(EmitterTest, OnEvent) {
  Foo obj;
  obj.foo = 1;

  Event1 event;
  event.bar = 2;

  auto listener = Event1Callback{1, 2};

  obj.On<Event1>(listener.MakeListener());

  ASSERT_TRUE(listener.ExpectCalled(0));
  ASSERT_FALSE(obj.Empty());

  obj.PublicEmit(event);

  ASSERT_TRUE(listener.ExpectCalled(1));
  ASSERT_FALSE(obj.Empty());

  obj.PublicEmit(event);

  ASSERT_TRUE(listener.ExpectCalled(2));
  ASSERT_FALSE(obj.Empty());
}

TEST(EmitterTest, OnceEvent) {
  Foo obj;
  obj.foo = 1;

  Event1 event;
  event.bar = 2;

  auto listener = Event1Callback{1, 2};

  obj.Once<Event1>(listener.MakeListener());
  obj.PublicEmit(event);

  ASSERT_TRUE(listener.ExpectCalled(1));
  ASSERT_TRUE(obj.Empty());

  obj.PublicEmit(event);

  ASSERT_TRUE(listener.ExpectCalled(1));
}

TEST(EmitterTest, MultiEvent) {
  Foo obj;
  obj.foo = 1;

  Event1 event1;
  event1.bar = 2;

  Event2 event2;
  event2.bar = 3;

  auto listener1 = Event1Callback{1, 2};
  auto listener2 = Event2Callback{1, 3};

  obj.On<Event1>(listener1.MakeListener());
  obj.Once<Event2>(listener2.MakeListener());

  obj.PublicEmit(event1);

  ASSERT_TRUE(listener1.ExpectCalled(1));
  ASSERT_TRUE(listener2.ExpectCalled(0));

  ASSERT_FALSE(obj.Empty());
  ASSERT_FALSE(obj.Empty<Event1>());
  ASSERT_FALSE(obj.Empty<Event2>());

  obj.PublicEmit(event2);

  ASSERT_TRUE(listener1.ExpectCalled(1));
  ASSERT_TRUE(listener2.ExpectCalled(1));

  ASSERT_FALSE(obj.Empty());
  ASSERT_FALSE(obj.Empty<Event1>());
  ASSERT_TRUE(obj.Empty<Event2>());
}

TEST(EmitterTest, ClearEvent) {
  Foo obj;
  obj.foo = 1;

  Event1 event;
  event.bar = 2;

  auto listener = Event1Callback{1, 2};

  obj.On<Event1>(listener.MakeListener());
  obj.PublicEmit(event);

  ASSERT_TRUE(listener.ExpectCalled(1));
  ASSERT_FALSE(obj.Empty());

  obj.Clear();

  ASSERT_TRUE(obj.Empty());
}

TEST(EmitterTest, MultiListener) {
  Foo obj;
  obj.foo = 1;

  Event1 event1;
  event1.bar = 2;

  auto listener1 = Event1Callback{1, 2};
  auto listener2 = Event1Callback{1, 2};

  obj.On<Event1>(listener1.MakeListener());
  obj.Once<Event1>(listener2.MakeListener());

  obj.PublicEmit(event1);

  ASSERT_TRUE(listener1.ExpectCalled(1));
  ASSERT_TRUE(listener1.ExpectCalled(1));

  ASSERT_FALSE(obj.Empty());
  ASSERT_FALSE(obj.Empty<Event1>());

  obj.PublicEmit(event1);

  ASSERT_TRUE(listener1.ExpectCalled(2));
  ASSERT_TRUE(listener2.ExpectCalled(1));

  ASSERT_FALSE(obj.Empty());
  ASSERT_FALSE(obj.Empty<Event1>());
}

