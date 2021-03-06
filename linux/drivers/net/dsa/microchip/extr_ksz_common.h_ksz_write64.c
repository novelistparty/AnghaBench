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
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct ksz_device {int /*<<< orphan*/ * regmap; } ;

/* Variables and functions */
 int regmap_bulk_write (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  swab32 (int) ; 
 int swab64 (int) ; 

__attribute__((used)) static inline int ksz_write64(struct ksz_device *dev, u32 reg, u64 value)
{
	u32 val[2];

	/* Ick! ToDo: Add 64bit R/W to regmap on 32bit systems */
	value = swab64(value);
	val[0] = swab32(value & 0xffffffffULL);
	val[1] = swab32(value >> 32ULL);

	return regmap_bulk_write(dev->regmap[2], reg, val, 2);
}