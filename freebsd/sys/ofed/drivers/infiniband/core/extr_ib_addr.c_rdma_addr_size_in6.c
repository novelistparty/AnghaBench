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
struct sockaddr_in6 {int dummy; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 int rdma_addr_size (struct sockaddr*) ; 

int rdma_addr_size_in6(struct sockaddr_in6 *addr)
{
	int ret = rdma_addr_size((struct sockaddr *) addr);

	return ret <= sizeof(*addr) ? ret : 0;
}