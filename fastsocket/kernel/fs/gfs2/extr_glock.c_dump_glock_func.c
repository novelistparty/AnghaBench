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
struct gfs2_glock {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dump_glock (int /*<<< orphan*/ *,struct gfs2_glock*) ; 

__attribute__((used)) static void dump_glock_func(struct gfs2_glock *gl)
{
	dump_glock(NULL, gl);
}