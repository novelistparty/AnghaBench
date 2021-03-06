#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_3__* adns_state ;
struct TYPE_6__ {scalar_t__ used; } ;
struct TYPE_5__ {scalar_t__ used; } ;
struct TYPE_7__ {int tcpserver; int tcpsocket; TYPE_2__ tcpsend; scalar_t__ tcprecv_skip; TYPE_1__ tcprecv; } ;

/* Variables and functions */
 int /*<<< orphan*/  adns_socket_close (int) ; 

__attribute__((used)) static void tcp_close(adns_state ads) {
  int serv;

  serv= ads->tcpserver;
  adns_socket_close(ads->tcpsocket);
  ads->tcpsocket= -1;
  ads->tcprecv.used= ads->tcprecv_skip= ads->tcpsend.used= 0;
}