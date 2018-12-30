// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <khala/base/serialization.hh>
#include <khala/base/utility.hh>

#include <vector>

namespace khala::serializer {

struct BinarySerializer {
  using Buffer_t = std::vector<char>;

  template<typename T>
  void PushValue(const char* name, T const& value);

  Buffer_t Build();

  void Reset();

 private:
  Buffer_t buffer_;
};

namespace detail {

template<typename T>
void PushIntegral(BinarySerializer::Buffer_t* buffer, T const& value) {
  static_assert(std::is_integral_v<T>);

  union {
    T v;
    char buf[sizeof(T)];
  } tmp;
  tmp.v = value;

  if constexpr (base::GetEndianOrder() == base::Endianness::HL_LITTLE_ENDIAN) {
    for (size_t i = 0; i < sizeof(T); i++) {
      buffer->push_back(tmp.buf[i]);
    }
  }
  if constexpr (base::GetEndianOrder() == base::Endianness::HL_BIG_ENDIAN) {
    for (size_t i = sizeof(T) - 1; i >= 0; i--) {
      buffer->push_back(tmp.buf[i]);
    }
  }

  // TODO(hawtian): support PDP-ENDIAN
}

template<typename T>
void PushValueImpl(BinarySerializer::Buffer_t* buffer, T const& value) {
  if constexpr (std::is_integral_v<T>) {
    PushIntegral(buffer, value);
  } else {
    if constexpr (base::IsIterable_v<T>) {
      PushIntegral(buffer, static_cast<uint32_t>(value.size()));
      for (auto& it : value) {
        PushValueImpl(buffer, it);
      }
    } else {
      auto buf = base::Serialize<BinarySerializer>(value);
      for (char ch : buf) {
        buffer->push_back(ch);
      }
    }
  }
}

template<typename T, typename U>
void PushValueImpl(BinarySerializer::Buffer_t* buffer,
                   std::pair<T, U> const& value) {
  PushValueImpl(buffer, value.first);
  PushValueImpl(buffer, value.second);
}

}  // namespace detail

template<typename T>
void BinarySerializer::PushValue(const char* name, T const& value) {
  detail::PushValueImpl(&buffer_, value);
}

}  // namespace khala::serializer
