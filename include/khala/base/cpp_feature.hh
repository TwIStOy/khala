// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

namespace khala::base {

#define PREFER_TRUE(cond) __builtin_expect(static_cast<bool>(cond), 1)
#define PREFER_FALSE(cond) __builtin_expect(static_cast<bool>(cond), 0)

#define MAYBE_UNUSED [[gnu::unused]]

}  // namespace khala::base
