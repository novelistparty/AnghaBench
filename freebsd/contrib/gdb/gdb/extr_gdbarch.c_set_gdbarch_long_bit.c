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
struct gdbarch {int long_bit; } ;

/* Variables and functions */

void
set_gdbarch_long_bit (struct gdbarch *gdbarch,
                      int long_bit)
{
  gdbarch->long_bit = long_bit;
}