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
typedef  int /*<<< orphan*/  am_node ;

/* Variables and functions */
 int ESTALE ; 

am_node *
amfs_error_lookup_child(am_node *mp, char *fname, int *error_return, int op)
{
  *error_return = ESTALE;
  return 0;
}