// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <sstream>
#include <string>
#include <vector>

namespace khala::base {

template<typename T>
std::string StringJoin(const T& vec, const std::string& sep) {
  std::ostringstream os;
  std::string s("");

  for (const auto& val : vec) {
    os << s << val;
    s = sep;
  }

  return os.str();
}

}  // namespace khala::base

