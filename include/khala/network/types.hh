// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <netinet/in.h>

#include <cstdint>
#include <string>

namespace khala::network {

enum class IpVersion : uint8_t { kIp4, kIp6 };

class Ipv4 {
 public:
  // network order
  Ipv4(uint32_t ip, uint16_t port) : ip_(ntohl(ip)), port_(ntohs(port)) {}

  explicit Ipv4(sockaddr_in const& address)
      : ip_(address.sin_addr.s_addr), port_(address.sin_port) {}

  std::string Str() const noexcept;

 private:
  uint32_t ip_;
  uint16_t port_;
};

}  // namespace khala::network

