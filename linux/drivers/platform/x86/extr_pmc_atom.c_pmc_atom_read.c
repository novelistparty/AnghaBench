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
typedef  int /*<<< orphan*/  u32 ;
struct pmc_dev {int /*<<< orphan*/  init; } ;

/* Variables and functions */
 int ENODEV ; 
 struct pmc_dev pmc_device ; 
 int /*<<< orphan*/  pmc_reg_read (struct pmc_dev*,int) ; 

int pmc_atom_read(int offset, u32 *value)
{
	struct pmc_dev *pmc = &pmc_device;

	if (!pmc->init)
		return -ENODEV;

	*value = pmc_reg_read(pmc, offset);
	return 0;
}