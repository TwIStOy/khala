// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <khala/base/reflection.hh>

#include <vector>
#include <utility>
#include <string>

namespace khala::base {

template<typename T>
constexpr bool IsSerializable = HasReflection_v<T>;

/*
 * Serializer
 *
 * template<typename T>
 * void PushValue(const char* name, T const& value);
 *
 * Buffer_t Build() const;
 *
 * void Reset();
 */
template<typename Serializer>
struct SerializationExecutor {
  template<typename T>
  static auto Serialize(T const& v) {
    static Serializer serializer_;

    if constexpr (!IsSerializable<T>) {
      throw std::invalid_argument("Object is not serializable.");
    }

    serializer_.Reset();

    SerializeImpl(&serializer_, v,
                  std::make_index_sequence<reflect::Size_v<T>>{});
    return serializer_.Build();
  }

 private:
  template<typename T>
  static void SerializeImpl(Serializer* serializer, T const& v,
                            std::index_sequence<>) {}

  template<typename T, size_t First, size_t... Rest>
  static void SerializeImpl(Serializer* serializer, T const& v,
                            std::index_sequence<First, Rest...>) {
    serializer->PushValue(reflect::MemberName<T>(First).Begin(),
                          reflect::MemberValue<First>(v));

    SerializeImpl(serializer, v, std::index_sequence<Rest...>{});
  }
};

template<typename Serializer, typename T>
auto Serialize(T const& v) {
  return SerializationExecutor<Serializer>::Serialize(v);
}

}  // namespace khala::base
