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
typedef  int /*<<< orphan*/  u8 ;
struct pmac_i2c_host_kw {unsigned int bsteps; scalar_t__ base; } ;
typedef  scalar_t__ reg_t ;

/* Variables and functions */
 int /*<<< orphan*/  readb (scalar_t__) ; 

__attribute__((used)) static inline u8 __kw_read_reg(struct pmac_i2c_host_kw *host, reg_t reg)
{
	return readb(host->base + (((unsigned int)reg) << host->bsteps));
}