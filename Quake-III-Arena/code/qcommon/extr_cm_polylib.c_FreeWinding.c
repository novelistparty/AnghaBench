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
typedef  int /*<<< orphan*/  winding_t ;

/* Variables and functions */
 int /*<<< orphan*/  Com_Error (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ERR_FATAL ; 
 int /*<<< orphan*/  Z_Free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  c_active_windings ; 

void FreeWinding (winding_t *w)
{
	if (*(unsigned *)w == 0xdeaddead)
		Com_Error (ERR_FATAL, "FreeWinding: freed a freed winding");
	*(unsigned *)w = 0xdeaddead;

	c_active_windings--;
	Z_Free (w);
}