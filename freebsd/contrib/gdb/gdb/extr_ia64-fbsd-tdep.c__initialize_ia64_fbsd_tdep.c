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

/* Variables and functions */
 int /*<<< orphan*/  GDB_OSABI_FREEBSD_ELF ; 
 int /*<<< orphan*/  bfd_arch_ia64 ; 
 int /*<<< orphan*/  gdbarch_register_osabi (int /*<<< orphan*/ ,unsigned long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ia64_fbsd_init_abi ; 

void
_initialize_ia64_fbsd_tdep (void)
{
  gdbarch_register_osabi (bfd_arch_ia64, 0ul, GDB_OSABI_FREEBSD_ELF,
                          ia64_fbsd_init_abi);
}