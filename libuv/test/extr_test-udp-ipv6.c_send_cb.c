#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  handle; } ;
typedef  TYPE_1__ uv_udp_send_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  CHECK_HANDLE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CHECK_REQ (TYPE_1__*) ; 
 int /*<<< orphan*/  send_cb_called ; 

__attribute__((used)) static void send_cb(uv_udp_send_t* req, int status) {
  CHECK_REQ(req);
  CHECK_HANDLE(req->handle);
  ASSERT(status == 0);
  send_cb_called++;
}