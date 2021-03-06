#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct pinctrl_dev {int dummy; } ;
struct atlas7_pmx {TYPE_2__* pctl_data; } ;
struct TYPE_4__ {TYPE_1__* grps; } ;
struct TYPE_3__ {char const* name; } ;

/* Variables and functions */
 struct atlas7_pmx* pinctrl_dev_get_drvdata (struct pinctrl_dev*) ; 

__attribute__((used)) static const char *atlas7_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
						u32 group)
{
	struct atlas7_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);

	return pmx->pctl_data->grps[group].name;
}