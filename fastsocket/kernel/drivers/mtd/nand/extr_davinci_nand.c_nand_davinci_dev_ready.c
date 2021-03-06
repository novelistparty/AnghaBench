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
struct mtd_info {int dummy; } ;
struct davinci_nand_info {int dummy; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NANDFSR_OFFSET ; 
 int davinci_nand_readl (struct davinci_nand_info*,int /*<<< orphan*/ ) ; 
 struct davinci_nand_info* to_davinci_nand (struct mtd_info*) ; 

__attribute__((used)) static int nand_davinci_dev_ready(struct mtd_info *mtd)
{
	struct davinci_nand_info *info = to_davinci_nand(mtd);

	return davinci_nand_readl(info, NANDFSR_OFFSET) & BIT(0);
}