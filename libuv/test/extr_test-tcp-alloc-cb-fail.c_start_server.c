#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uv_stream_t ;
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  TEST_PORT ; 
 int /*<<< orphan*/  connection_cb ; 
 int /*<<< orphan*/  server ; 
 int /*<<< orphan*/  uv_default_loop () ; 
 scalar_t__ uv_ip4_addr (char*,int /*<<< orphan*/ ,struct sockaddr_in*) ; 
 scalar_t__ uv_listen (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_tcp_bind (int /*<<< orphan*/ *,struct sockaddr*,int /*<<< orphan*/ ) ; 
 scalar_t__ uv_tcp_init (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void start_server(void) {
  struct sockaddr_in addr;

  ASSERT(0 == uv_ip4_addr("0.0.0.0", TEST_PORT, &addr));

  ASSERT(0 == uv_tcp_init(uv_default_loop(), &server));
  ASSERT(0 == uv_tcp_bind(&server, (struct sockaddr*) &addr, 0));
  ASSERT(0 == uv_listen((uv_stream_t*) &server, 128, connection_cb));
}