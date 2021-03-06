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
typedef  int /*<<< orphan*/  CORE_ADDR ;

/* Variables and functions */
 int annotation_level ; 
 int /*<<< orphan*/  gdb_stdout ; 
 int /*<<< orphan*/  print_address_numeric (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf_filtered (char*,...) ; 

void
annotate_frame_begin (int level, CORE_ADDR pc)
{
  if (annotation_level == 2)
    {
      printf_filtered ("\n\032\032frame-begin %d 0x", level);
      print_address_numeric (pc, 0, gdb_stdout);
      printf_filtered ("\n");
    }
}