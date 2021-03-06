#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ucf_name ;
struct pmc_info {int /*<<< orphan*/  pm_enabled; int /*<<< orphan*/  pm_class; int /*<<< orphan*/  pm_name; } ;
struct pmc_hw {int phw_state; struct pmc* phw_pmc; } ;
struct pmc {int dummy; } ;
struct TYPE_2__ {struct pmc_hw* pc_uncorepmcs; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  PMC_CLASS_UCF ; 
 int PMC_NAME_MAX ; 
 int PMC_PHW_FLAG_IS_ENABLED ; 
 int /*<<< orphan*/  TRUE ; 
 int copystr (char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 
 TYPE_1__** uncore_pcpu ; 
 int uncore_ucf_ri ; 

__attribute__((used)) static int
ucf_describe(int cpu, int ri, struct pmc_info *pi, struct pmc **ppmc)
{
	int error;
	struct pmc_hw *phw;
	char ucf_name[PMC_NAME_MAX];

	phw = &uncore_pcpu[cpu]->pc_uncorepmcs[ri + uncore_ucf_ri];

	(void) snprintf(ucf_name, sizeof(ucf_name), "UCF-%d", ri);
	if ((error = copystr(ucf_name, pi->pm_name, PMC_NAME_MAX,
	    NULL)) != 0)
		return (error);

	pi->pm_class = PMC_CLASS_UCF;

	if (phw->phw_state & PMC_PHW_FLAG_IS_ENABLED) {
		pi->pm_enabled = TRUE;
		*ppmc          = phw->phw_pmc;
	} else {
		pi->pm_enabled = FALSE;
		*ppmc          = NULL;
	}

	return (0);
}