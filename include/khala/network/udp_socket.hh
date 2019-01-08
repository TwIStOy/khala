// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include "khala/base/buffer.hh"
#include "khala/base/emitter.hh"
#include "khala/base/event_loop.hh"
#include "khala/network/types.hh"

namespace khala::network {

struct UdpDataEvent {
  GeneralAddress from_addr;
  base::UniqueBuffer data;
  bool partial;
};

// template<typename T, typename U>
class Handler {
 protected:
  static void AllocateCallback(uv_handle_t* handle, size_t suggtested_size,
                               uv_buf_t* buf) {
    auto size = static_cast<size_t>(suggtested_size);
    *buf = uv_buf_init(new char[size], size);
  }
};

// ipv4 only
class UdpSocket final : public base::Emitter<UdpSocket>, public Handler {
 public:
  constexpr static size_t kDefaultSendQueueSize = 1024 * 4 * 4;
  constexpr static size_t kDefaultRecvQueueSize = 1024 * 8;

  UdpSocket(base::EventLoop* loop,
            size_t send_queue_size = kDefaultSendQueueSize,
            size_t recv_queue_size = kDefaultRecvQueueSize) noexcept;

  uint16_t GetLocalPort() const noexcept;

  bool Bind(Ipv4 const& addr) noexcept;

 private:
  static void ReceiveCallback(uv_udp_t* handle, ssize_t nread,
                              const uv_buf_t* buf, const sockaddr* addr,
                              unsigned flags) {
    auto self = static_cast<UdpSocket*>(handle->data);
    auto data = base::UniqueBuffer::MoveFrom(buf->base, buf->len);

    if (nread > 0) {
      self->Emit(UdpDataEvent{GeneralAddress::FromSockAddr(addr),
                              std::move(data),
                              !(0 == (flags & UV_UDP_PARTIAL))});
    } else if (nread == 0 && addr == nullptr) {
      // empty is ok
    } else if (nread == 0 && addr != nullptr) {
      self->Emit(UdpDataEvent{GeneralAddress::FromSockAddr(addr),
                              std::move(data),
                              !(0 == (flags & UV_UDP_PARTIAL))});
    } else {
      self->Emit(base::UvErrorEvent{nread});
    }
  }

 private:
  base::EventLoop* loop_;
  uv_udp_t uv_udp_socket_;
};

}  // namespace khala::network

