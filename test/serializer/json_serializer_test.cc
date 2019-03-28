// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/serializer/json.hh>

#include <iostream>
#include <optional>

struct InnerStruct {
  bool foo;
};
struct JsonSerializerTestType {
  int foo;
  std::string bar;
  double foobar;
  std::vector<std::string> arr;
  std::optional<double> op_double;
  InnerStruct inner;
};
REFLECTION(JsonSerializerTestType, foo, bar, foobar, arr, op_double, inner);
REFLECTION(InnerStruct, foo);

TEST(JsonSerializerTest, Gen) {
  using khala::base::SerializationExecutor;
  using khala::base::Serialize;
  using khala::serializer::JsonSerializer;

  JsonSerializerTestType obj;
  obj.foo = 12;
  obj.bar = "test_bar";
  obj.foobar = 1.23;
  obj.inner.foo = true;
  obj.arr = {{"a", "b", "c"}};
  obj.op_double = 123;

  std::cout << Serialize<JsonSerializer>(obj).dump(2) << std::endl;
}
