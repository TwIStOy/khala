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

}  // namespace khala::network

