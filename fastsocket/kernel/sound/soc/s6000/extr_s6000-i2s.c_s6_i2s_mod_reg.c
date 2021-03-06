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
typedef  int u32 ;
struct s6000_i2s_dev {int dummy; } ;

/* Variables and functions */
 int s6_i2s_read_reg (struct s6000_i2s_dev*,int) ; 
 int /*<<< orphan*/  s6_i2s_write_reg (struct s6000_i2s_dev*,int,int) ; 

__attribute__((used)) static inline void s6_i2s_mod_reg(struct s6000_i2s_dev *dev, int reg,
				  u32 mask, u32 val)
{
	val ^= s6_i2s_read_reg(dev, reg) & ~mask;
	s6_i2s_write_reg(dev, reg, val);
}