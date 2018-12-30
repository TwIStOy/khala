// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <khala/base/serialization.hh>
#include <third_party/json.hpp>

namespace khala::serializer {

struct JsonSerializer {
  using Json_t = nlohmann::json;

  template<typename T>
  void PushValue(const char* name, T const& value);

  Json_t Build();

  void Reset();

 private:
  template<typename T>
  Json_t ToJson(T const& value);

 private:
  Json_t json_;
};

template<typename T>
void JsonSerializer::PushValue(const char* name, T const& value) {
  if constexpr (base::IsSerializable<T>) {
    json_.emplace(name, base::Serialize<JsonSerializer>(value));
  } else {
    json_.emplace(name, ToJson(value));
  }
}

template<typename T>
JsonSerializer::Json_t JsonSerializer::ToJson(T const& value) {
  static_assert(std::is_constructible_v<Json_t, T>,
                "Simple type can't convert to Json_t.");
  return JsonSerializer::Json_t(value);
}

}  // namespace khala::serializer
