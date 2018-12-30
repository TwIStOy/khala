// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/reflection.hh>
#include <khala/base/serialization.hh>
#include <khala/serializer/binary.hh>

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

struct InnerTestType {
  char foo;
};
struct BinaryTestType {
  int foo;
  std::string bar;
  std::vector<std::string> arr;
  InnerTestType inner;
};
REFLECTION(InnerTestType, foo);
REFLECTION(BinaryTestType, foo, bar, arr, inner);

TEST(BinarySerializerTest, Gen) {
  using khala::base::SerializationExecutor;
  using khala::base::Serialize;
  using khala::serializer::BinarySerializer;

  BinaryTestType obj;
  obj.foo = 12;
  obj.bar = "test_bar";
  obj.arr = {"a", "b", "c"};
  obj.inner.foo = 'a';

  auto buf = Serialize<BinarySerializer>(obj);
  std::cout << "Size: " << buf.size() << std::endl;
  std::cout << "Buffer: " << std::hex << std::setfill('0');
  for (char ch : buf) {
    std::cout << "0x" << std::setw(2) << static_cast<uint32_t>(ch) << ' ';
  }
  std::cout << std::endl;
}
