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
typedef  int /*<<< orphan*/  ip_addr_t ;

/* Variables and functions */
 char* ipaddr_ntoa_r (int /*<<< orphan*/  const*,char*,int) ; 

char *
ipaddr_ntoa(const ip_addr_t *addr)
{
  static char str[16];
  return ipaddr_ntoa_r(addr, str, 16);
}