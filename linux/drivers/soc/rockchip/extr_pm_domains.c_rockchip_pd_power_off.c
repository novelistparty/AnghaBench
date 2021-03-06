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
struct rockchip_pm_domain {int dummy; } ;
struct generic_pm_domain {int dummy; } ;

/* Variables and functions */
 int rockchip_pd_power (struct rockchip_pm_domain*,int) ; 
 struct rockchip_pm_domain* to_rockchip_pd (struct generic_pm_domain*) ; 

__attribute__((used)) static int rockchip_pd_power_off(struct generic_pm_domain *domain)
{
	struct rockchip_pm_domain *pd = to_rockchip_pd(domain);

	return rockchip_pd_power(pd, false);
}