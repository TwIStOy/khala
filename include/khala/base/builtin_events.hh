// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include <type_traits>

namespace khala::base {

struct UvErrorEvent {
  template<typename U, typename std::enable_if_t<std::is_integral_v<U>>>
  explicit UvErrorEvent(U val) noexcept : error_code_{static_cast<int>(val)} {}

  inline const char* What() const noexcept { return uv_strerror(error_code_); }

  inline const char* Name() const noexcept { return uv_err_name(error_code_); }

  inline int Code() const noexcept { return error_code_; }

  operator bool() const noexcept { return error_code_; }

 private:
  const int error_code_;
};

}  // namespace khala::base

