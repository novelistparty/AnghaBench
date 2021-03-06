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
struct target_ops {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  baudrate ; 
 int /*<<< orphan*/  dev_name ; 
 int /*<<< orphan*/  printf_unfiltered (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
e7000_files_info (struct target_ops *ops)
{
  printf_unfiltered ("\tAttached to %s at %d baud.\n", dev_name, baudrate);
}