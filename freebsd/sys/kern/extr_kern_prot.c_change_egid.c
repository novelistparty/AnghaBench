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
struct ucred {int /*<<< orphan*/ * cr_groups; } ;
typedef  int /*<<< orphan*/  gid_t ;

/* Variables and functions */

void
change_egid(struct ucred *newcred, gid_t egid)
{

	newcred->cr_groups[0] = egid;
}