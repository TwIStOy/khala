// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <arpa/inet.h>
#include <netinet/in.h>

#include <cstdint>
#include <string>

#include "fmt/format.h"

namespace khala::network {

enum class IpVersion : uint8_t { kIp4, kIp6 };

class Ipv4 {
 public:
  // network order
  Ipv4(uint32_t ip, uint16_t port) : ip_(ip), port_(port) {}

  explicit Ipv4(sockaddr_in const& address)
      : ip_(address.sin_addr.s_addr), port_(address.sin_port) {}

  inline std::string Str() const { return fmt::format("{}", *this); }

  Ipv4& operator=(sockaddr_in const& addr) noexcept;

  inline uint32_t Ip() const noexcept { return ntohl(ip_); }

  inline uint32_t Port() const noexcept { return ntohs(port_); }

 private:
  friend struct fmt::formatter<khala::network::Ipv4>;

  uint32_t ip_;
  uint16_t port_;
};

}  // namespace khala::network

template<>
struct fmt::formatter<sockaddr_in> {
  template<typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  }

  template<typename FormatContext>
  auto format(sockaddr_in const& addr, FormatContext& ctx) {
    return format_to(ctx.out(), "{}:{}", inet_ntoa(addr.sin_addr),
                     ntohl(addr.sin_port));
  }
};

template<>
struct fmt::formatter<khala::network::Ipv4> {
  template<typename ParseContext>
  constexpr auto parse(ParseContext& ctx) {
    return ctx.begin();
  }

  template<typename FormatContext>
  auto format(khala::network::Ipv4 const& addr, FormatContext& ctx) {
    in_addr ip{addr.ip_};

    return format_to(ctx.out(), "{}:{}", inet_ntoa(ip), ntohl(addr.port_));
  }
};

