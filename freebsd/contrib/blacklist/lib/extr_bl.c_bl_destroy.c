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
typedef  int /*<<< orphan*/  bl_t ;

/* Variables and functions */
 int /*<<< orphan*/  bl_reset (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 

void
bl_destroy(bl_t b)
{
	bl_reset(b, false);
	free(b);
}