#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ error; } ;

/* Variables and functions */
 long long do_rpc_fetch_long (scalar_t__*) ; 
 TYPE_1__ tl ; 

long long tl_parse_long (void) {
  if (tl.error) { return -1; }
  return do_rpc_fetch_long (&tl.error);
}