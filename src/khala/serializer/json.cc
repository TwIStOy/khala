// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <khala/serializer/json.hh>

#include <string>
#include <type_traits>

namespace khala::serializer {

void JsonSerializer::Reset() { json_ = Json_t{}; }

JsonSerializer::Json_t JsonSerializer::Build() { return std::move(json_); }

}  // namespace khala::serializer
