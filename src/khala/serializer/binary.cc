// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <khala/base/serialization.hh>
#include <khala/base/utility.hh>
#include <khala/serializer/binary.hh>

#include <map>
#include <set>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace khala::serializer {

void BinarySerializer::Reset() {
  buffer_ = Buffer_t{};
  detail::PushIntegral(&buffer_, static_cast<uint32_t>(0));
}

BinarySerializer::Buffer_t BinarySerializer::Build() {
  Buffer_t buf;
  detail::PushIntegral(&buf, static_cast<uint32_t>(buffer_.size()));
  for (uint32_t i = 0; i < sizeof(uint32_t); i++) {
    buffer_[i] = buf[i];
  }
  return std::move(buffer_);
}

}  // namespace khala::serializer
