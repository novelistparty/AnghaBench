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
struct generic_pm_domain {int /*<<< orphan*/  mlock; } ;

/* Variables and functions */
 void mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void genpd_unlock_mtx(struct generic_pm_domain *genpd)
{
	return mutex_unlock(&genpd->mlock);
}