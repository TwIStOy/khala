// Copyright (c) 2018 TwIStOy(Hawtian Wang). All rights reserved.
// Author: Hawtian.Wang (twistoy.wang@gmail.com)
//

#pragma once  // NOLINT

#include <uv.h>

#include <khala/base/emitter.hh>
#include <khala/base/event_loop.hh>
#include <khala/network/types.hh>

namespace khala::network {

struct PacketReceivedEvent {};

class UdpSocket final : base::Emitter<UdpSocket> {
 public:
  constexpr static size_t kDefaultSendQueueSize = 2014 * 4 * 4;
  constexpr static size_t kDefaultRecvQueueSize = 2014 * 8;

  UdpSocket(base::EventLoop* loop,
            size_t send_queue_size = kDefaultSendQueueSize,
            size_t recv_queue_size = kDefaultRecvQueueSize) noexcept;

  uint16_t GetLocalPort() const noexcept;

 private:
  base::EventLoop* loop_;
  uv_udp_t uv_udp_socket_;
};



}  // namespace khala::network

/*
uv_loop_t *loop;
uv_udp_t send_socket;
uv_udp_t recv_socket;

int main() {
    loop = uv_default_loop();

    uv_udp_init(loop, &recv_socket);
    struct sockaddr_in recv_addr;
    uv_ip4_addr("0.0.0.0", 68, &recv_addr);
    uv_udp_bind(&recv_socket, (const struct sockaddr *)&recv_addr, UV_UDP_REUSEADDR);
    uv_udp_recv_start(&recv_socket, alloc_buffer, on_read);

    uv_udp_init(loop, &send_socket);
    struct sockaddr_in broadcast_addr;
    uv_ip4_addr("0.0.0.0", 0, &broadcast_addr);
    uv_udp_bind(&send_socket, (const struct sockaddr *)&broadcast_addr, 0);
    uv_udp_set_broadcast(&send_socket, 1);

    uv_udp_send_t send_req;
    uv_buf_t discover_msg = make_discover_msg();

    struct sockaddr_in send_addr;
    uv_ip4_addr("255.255.255.255", 67, &send_addr);
    uv_udp_send(&send_req, &send_socket, &discover_msg, 1, (const struct sockaddr *)&send_addr, on_send);

    return uv_run(loop, UV_RUN_DEFAULT);
}
*/
