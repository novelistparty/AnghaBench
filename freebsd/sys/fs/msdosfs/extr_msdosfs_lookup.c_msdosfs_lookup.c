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
struct vop_cachedlookup_args {int /*<<< orphan*/  a_cnp; int /*<<< orphan*/  a_vpp; int /*<<< orphan*/  a_dvp; } ;

/* Variables and functions */
 int msdosfs_lookup_ (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

int
msdosfs_lookup(struct vop_cachedlookup_args *ap)
{

	return (msdosfs_lookup_(ap->a_dvp, ap->a_vpp, ap->a_cnp, NULL));
}