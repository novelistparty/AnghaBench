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
struct gdbarch {int deprecated_call_dummy_length; } ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf_unfiltered (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gdb_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gdb_stdlog ; 
 int gdbarch_debug ; 

int
gdbarch_deprecated_call_dummy_length (struct gdbarch *gdbarch)
{
  gdb_assert (gdbarch != NULL);
  if (gdbarch_debug >= 2)
    fprintf_unfiltered (gdb_stdlog, "gdbarch_deprecated_call_dummy_length called\n");
  return gdbarch->deprecated_call_dummy_length;
}