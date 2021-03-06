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
struct mtd_info {scalar_t__ size; int (* _block_isbad ) (struct mtd_info*,scalar_t__) ;} ;
typedef  scalar_t__ loff_t ;

/* Variables and functions */
 int EINVAL ; 
 int stub1 (struct mtd_info*,scalar_t__) ; 

int mtd_block_isbad(struct mtd_info *mtd, loff_t ofs)
{
	if (ofs < 0 || ofs >= mtd->size)
		return -EINVAL;
	if (!mtd->_block_isbad)
		return 0;
	return mtd->_block_isbad(mtd, ofs);
}