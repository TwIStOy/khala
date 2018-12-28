// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <cstdint>
#include <type_traits>

namespace khala::base {

enum Endianness : uint32_t {
  HL_LITTLE_ENDIAN   = 0x00000001,
  HL_BIG_ENDIAN      = 0x01000000,
  HL_PDP_ENDIAN      = 0x00010000,
  HL_UNKNOWN_ENDIAN  = 0xFFFFFFFF
};

/**
 * A simple function that can be used to help determine a program's endianness
 * at compile-time.
 */
constexpr Endianness GetEndianOrder() {
  if ((1 & 0xFFFFFFFF) == HL_LITTLE_ENDIAN) {
    return HL_LITTLE_ENDIAN;
  }
  if ((1 & 0xFFFFFFFF) == HL_BIG_ENDIAN) {
    return HL_BIG_ENDIAN;
  }
  if ((1 & 0xFFFFFFFF) == HL_PDP_ENDIAN) {
    return HL_PDP_ENDIAN;
  } else {
    return HL_UNKNOWN_ENDIAN;
  }
}

template<typename T,
    typename = std::void_t<>,
    typename = std::void_t<>,
    typename = std::void_t<>>
struct IsIterable : std::false_type {};

template<typename T>
struct IsIterable<
    T, std::void_t<decltype(std::declval<T>().size())>,
    std::void_t<decltype(std::declval<T>().begin())>,
    std::void_t<decltype(std::declval<T>().end())>> : std::true_type {};

template<typename T>
constexpr bool IsIterable_v = IsIterable<T>::value;

} // namespace khala::base
