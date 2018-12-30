// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <cstdint>
#include <cstdlib>
#include <stdexcept>

namespace khala::base {

class StringRef;
constexpr bool operator==(StringRef a, StringRef b);

class StringRef {
 public:
  template<size_t N>
  constexpr StringRef(const char (&arr)[N]) : begin_(arr), size_(N - 1) {
    static_assert(N >= 1, "const string literal should not be empty.");
  }

  constexpr StringRef(const char* buf, size_t len) : begin_(buf), size_(len) {}

  constexpr char operator[](uint32_t i) const {
    if (i >= size_) {
      throw std::invalid_argument("size is not good");
    }
    return begin_[i];
  }

  constexpr const char* Begin() const { return begin_; }
  constexpr const char* End() const { return begin_ + size_; }
  constexpr size_t Size() const { return size_; }

 private:
  constexpr static bool StringEqual(const char* a, const char* b, size_t N) {
    if (*a == 0 && *b == 0 && N == 0) return true;
    if (*a == 0 || *b == 0) return false;
    if (N == 0) return true;
    if (*a != *b) return false;
    return StringEqual(a + 1, b + 1, N - 1);
  }

  friend constexpr bool operator==(StringRef a, StringRef b);

 private:
  const char* const begin_;
  size_t size_;
};

constexpr StringRef operator"" _ref(const char* str, size_t N) {
  return StringRef{str, N};
}

constexpr bool operator==(StringRef a, StringRef b) {
  if (a.Size() != b.Size()) return false;
  return StringRef::StringEqual(a.Begin(), b.Begin(), a.Size());
}

}  // namespace khala::base
