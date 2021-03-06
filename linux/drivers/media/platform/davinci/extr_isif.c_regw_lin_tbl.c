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
typedef  scalar_t__ u32 ;
struct TYPE_2__ {scalar_t__ linear_tbl1_addr; scalar_t__ linear_tbl0_addr; } ;

/* Variables and functions */
 int /*<<< orphan*/  __raw_writel (scalar_t__,scalar_t__) ; 
 TYPE_1__ isif_cfg ; 

__attribute__((used)) static inline void regw_lin_tbl(u32 val, u32 offset, int i)
{
	if (!i)
		__raw_writel(val, isif_cfg.linear_tbl0_addr + offset);
	else
		__raw_writel(val, isif_cfg.linear_tbl1_addr + offset);
}