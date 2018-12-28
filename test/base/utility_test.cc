// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <gtest/gtest.h>
#include <khala/base/utility.hh>

#include <map>
#include <string>
#include <unordered_set>
#include <set>
#include <unordered_set>
#include <vector>

TEST(UtilityTest, Iterable) {
  using khala::base::IsIterable_v;

  using MapType = std::map<int, int>;
  using UMapType = std::map<int, int>;

  EXPECT_TRUE(IsIterable_v<std::string>);
  EXPECT_TRUE(IsIterable_v<std::vector<int>>);
  EXPECT_TRUE(IsIterable_v<MapType>);
  EXPECT_TRUE(IsIterable_v<UMapType>);
  EXPECT_TRUE(IsIterable_v<std::set<int>>);
  EXPECT_TRUE(IsIterable_v<std::unordered_set<int>>);
}
