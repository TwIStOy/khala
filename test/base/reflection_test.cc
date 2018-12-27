// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/reflection.hh>

struct FooStructFalse {
  int foo;
  int bar;
  int foobar;
};
struct FooStruct {
  int foo;
  int bar;
  int foobar;
};
REFLECTION(FooStruct, foo, bar, foobar);

namespace khala::base {

TEST(ReflectionTest, SimpleTest) {
  EXPECT_TRUE(HasReflection_v<FooStruct>);
  EXPECT_FALSE(HasReflection_v<FooStructFalse>);
}

TEST(ReflectionTest, SimpleSize) {
  EXPECT_EQ(reflect::Size_v<FooStruct>, 3);
}

TEST(ReflectionTest, SimpleName) {
  EXPECT_STREQ(reflect::ClassName<FooStruct>.Begin(), "FooStruct");
}

TEST(ReflectionTest, SimpleMemberName) {
  EXPECT_STREQ(reflect::MemberName<FooStruct>(0).Begin(), "foo");
  EXPECT_STREQ(reflect::MemberName<FooStruct>(1).Begin(), "bar");
  EXPECT_STREQ(reflect::MemberName<FooStruct>(2).Begin(), "foobar");
}

TEST(ReflectionTest, SimpleGetValue) {
  FooStruct instance{1, 2, 3};
  EXPECT_EQ(reflect::MemberValue<0>(instance), 1);
  EXPECT_EQ(reflect::MemberValue<1>(instance), 2);
  EXPECT_EQ(reflect::MemberValue<2>(instance), 3);
}

TEST(ReflectionTest, SimpleSetValue) {
  FooStruct instance{0, 0, 0};
  reflect::MemberValue<0>(instance) = 1;
  reflect::MemberValue<1>(instance) = 2;
  reflect::MemberValue<2>(instance) = 3;
  EXPECT_EQ(instance.foo, 1);
  EXPECT_EQ(instance.bar, 2);
  EXPECT_EQ(instance.foobar, 3);
}

}  // namespace khala::base
