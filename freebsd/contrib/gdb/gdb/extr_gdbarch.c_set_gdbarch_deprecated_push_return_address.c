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
struct gdbarch {int /*<<< orphan*/  deprecated_push_return_address; } ;
typedef  int /*<<< orphan*/  gdbarch_deprecated_push_return_address_ftype ;

/* Variables and functions */

void
set_gdbarch_deprecated_push_return_address (struct gdbarch *gdbarch,
                                            gdbarch_deprecated_push_return_address_ftype deprecated_push_return_address)
{
  gdbarch->deprecated_push_return_address = deprecated_push_return_address;
}