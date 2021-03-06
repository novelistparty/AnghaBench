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
struct mii_bus {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  __ar7240sw_reg_read (struct mii_bus*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reg_mutex ; 

__attribute__((used)) static u32 ar7240sw_reg_read(struct mii_bus *mii, u32 reg_addr)
{
	u32 ret;

	mutex_lock(&reg_mutex);
	ret = __ar7240sw_reg_read(mii, reg_addr);
	mutex_unlock(&reg_mutex);

	return ret;
}