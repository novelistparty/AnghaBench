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
struct nand_chip {int dummy; } ;
struct mtd_oob_ops {scalar_t__ mode; int /*<<< orphan*/  datbuf; scalar_t__ retlen; } ;
struct mtd_info {int dummy; } ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int ENOTSUPP ; 
 scalar_t__ MTD_OPS_AUTO_OOB ; 
 scalar_t__ MTD_OPS_PLACE_OOB ; 
 scalar_t__ MTD_OPS_RAW ; 
 struct nand_chip* mtd_to_nand (struct mtd_info*) ; 
 int nand_do_read_oob (struct nand_chip*,int /*<<< orphan*/ ,struct mtd_oob_ops*) ; 
 int nand_do_read_ops (struct nand_chip*,int /*<<< orphan*/ ,struct mtd_oob_ops*) ; 
 int nand_get_device (struct nand_chip*) ; 
 int /*<<< orphan*/  nand_release_device (struct nand_chip*) ; 

__attribute__((used)) static int nand_read_oob(struct mtd_info *mtd, loff_t from,
			 struct mtd_oob_ops *ops)
{
	struct nand_chip *chip = mtd_to_nand(mtd);
	int ret;

	ops->retlen = 0;

	if (ops->mode != MTD_OPS_PLACE_OOB &&
	    ops->mode != MTD_OPS_AUTO_OOB &&
	    ops->mode != MTD_OPS_RAW)
		return -ENOTSUPP;

	ret = nand_get_device(chip);
	if (ret)
		return ret;

	if (!ops->datbuf)
		ret = nand_do_read_oob(chip, from, ops);
	else
		ret = nand_do_read_ops(chip, from, ops);

	nand_release_device(chip);
	return ret;
}