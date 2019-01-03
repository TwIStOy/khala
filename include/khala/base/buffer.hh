// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <cstdint>
#include <memory>

namespace khala::base {

template<template<typename> typename PtrType>
class __Buffer : std::enable_shared_from_this<__Buffer<PtrType>> {
 public:
  constexpr static size_t kMaxBufferSize = 2048;

  static __Buffer Create(size_t size = kMaxBufferSize) {
    return __Buffer(size);
  }

  static __Buffer Create(char* buffer, size_t size) {
    __Buffer buf(size);
    std::copy(buffer, buffer + size, buf.Begin());
    return buf;
  }

 public:
  __Buffer(__Buffer const&) = default;
  __Buffer(__Buffer&&) = default;

  inline const char* Begin() const { return buffer_.get(); }
  inline const char* End() const { return buffer_.get() + capacity_; }

  inline char* Begin() { return buffer_.get(); }
  inline char* End() { return buffer_.get() + capacity_; }

  inline size_t Capacity() const { return capacity_; }

  inline PtrType<char[]>& TakeBuffer() { return buffer_; }

 private:
  explicit __Buffer(size_t size) : capacity_(size), buffer_(new char[size]) {
    memset(buffer_.get(), 0, size);
  }

 private:
  size_t capacity_;
  PtrType<char[]> buffer_;
};

template<typename T>
using UniquePtr = std::unique_ptr<T>;

using SharedBuffer = __Buffer<std::shared_ptr>;
using UniqueBuffer = __Buffer<UniquePtr>;

}  // namespace khala::base

