// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <khala/network/types.hh>

namespace khala::network {

Ipv4& Ipv4::operator=(sockaddr_in const& addr) noexcept {
  ip_ = addr.sin_addr.s_addr;
  port_ = addr.sin_port;
  return *this;
}

Ipv4 Ipv4::From(std::string const& str, uint16_t port) {
  struct sockaddr_in ip_addr;
  inet_aton(str.c_str(), &ip_addr.sin_addr);
  return Ipv4{ip_addr.sin_addr.s_addr, htons(port)};
}

Ipv4::operator sockaddr_in() const {
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = ip_;
  addr.sin_port = port_;
  return addr;
}

}  // namespace khala::network

