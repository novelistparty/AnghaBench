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
 int /*<<< orphan*/  annotate_signal_hook () ; 
 int annotation_level ; 
 int /*<<< orphan*/  printf_filtered (char*) ; 

void
annotate_signal (void)
{
  if (annotate_signal_hook)
    annotate_signal_hook ();

  if (annotation_level > 1)
    printf_filtered ("\n\032\032signal\n");
}