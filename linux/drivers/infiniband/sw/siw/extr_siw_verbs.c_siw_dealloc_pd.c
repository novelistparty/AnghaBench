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
struct siw_device {int /*<<< orphan*/  num_pd; } ;
struct ib_udata {int dummy; } ;
struct ib_pd {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_dec (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  siw_dbg_pd (struct ib_pd*,char*) ; 
 struct siw_device* to_siw_dev (int /*<<< orphan*/ ) ; 

void siw_dealloc_pd(struct ib_pd *pd, struct ib_udata *udata)
{
	struct siw_device *sdev = to_siw_dev(pd->device);

	siw_dbg_pd(pd, "free PD\n");
	atomic_dec(&sdev->num_pd);
}