// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#include <glog/logging.h>

#include "fmt/format.h"
#include "khala/base/builtin_events.hh"
#include "khala/network/udp_socket.hh"

namespace khala::network {

using fmt::operator"" _format;

bool UdpSocket::Bind(Ipv4 const& addr) noexcept {
  auto saddr = static_cast<struct sockaddr_in>(addr);

  int rc = uv_udp_bind(&uv_udp_socket_,
                       reinterpret_cast<const struct sockaddr*>(&saddr),
                       UV_UDP_REUSEADDR);

  if (rc == 0) {
    return true;
  }

  LOG(WARNING) << "Bind to {} failed. Because: {}"_format(
      addr, base::UvErrorEvent{rc}.What());

  return false;
}

}  // namespace khala::network
