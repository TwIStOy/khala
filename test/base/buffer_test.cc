// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/buffer.hh>

#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

TEST(BufferTest, Compile) {
  using khala::base::SharedBuffer;
  using khala::base::UniqueBuffer;

  {
    SharedBuffer buffer = SharedBuffer::Create(512);
    SharedBuffer buffer2 =
        SharedBuffer::Create(buffer.Begin(), buffer.Capacity());

    auto buffer3 = buffer;
  }

  {
    UniqueBuffer buffer = UniqueBuffer::Create(512);
    UniqueBuffer buffer2 = std::move(buffer);
  }
}

