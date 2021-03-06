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
struct gdbarch {scalar_t__ deprecated_register_virtual_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  gdb_assert (int /*<<< orphan*/ ) ; 
 scalar_t__ generic_register_size ; 

int
gdbarch_deprecated_register_virtual_size_p (struct gdbarch *gdbarch)
{
  gdb_assert (gdbarch != NULL);
  return gdbarch->deprecated_register_virtual_size != generic_register_size;
}