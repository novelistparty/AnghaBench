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
typedef  int /*<<< orphan*/  xdfenv_t ;

/* Variables and functions */
 int xdl_recs_copy_0 (int,int /*<<< orphan*/ *,int,int,int,int,char*) ; 

__attribute__((used)) static int xdl_orig_copy(xdfenv_t *xe, int i, int count, int needs_cr, int add_nl, char *dest)
{
	return xdl_recs_copy_0(1, xe, i, count, needs_cr, add_nl, dest);
}