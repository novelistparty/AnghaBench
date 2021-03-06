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
typedef  int uint32_t ;
struct i2c_adapter {int dummy; } ;
struct amdgpu_i2c_bus_rec {int mask_clk_mask; int mask_data_mask; int /*<<< orphan*/  mask_data_reg; int /*<<< orphan*/  mask_clk_reg; } ;
struct amdgpu_i2c_chan {int /*<<< orphan*/  mutex; struct amdgpu_i2c_bus_rec rec; TYPE_1__* dev; } ;
struct amdgpu_device {int dummy; } ;
struct TYPE_2__ {struct amdgpu_device* dev_private; } ;

/* Variables and functions */
 int RREG32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WREG32 (int /*<<< orphan*/ ,int) ; 
 struct amdgpu_i2c_chan* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void amdgpu_i2c_post_xfer(struct i2c_adapter *i2c_adap)
{
	struct amdgpu_i2c_chan *i2c = i2c_get_adapdata(i2c_adap);
	struct amdgpu_device *adev = i2c->dev->dev_private;
	struct amdgpu_i2c_bus_rec *rec = &i2c->rec;
	uint32_t temp;

	/* unmask the gpio pins for software use */
	temp = RREG32(rec->mask_clk_reg) & ~rec->mask_clk_mask;
	WREG32(rec->mask_clk_reg, temp);
	temp = RREG32(rec->mask_clk_reg);

	temp = RREG32(rec->mask_data_reg) & ~rec->mask_data_mask;
	WREG32(rec->mask_data_reg, temp);
	temp = RREG32(rec->mask_data_reg);

	mutex_unlock(&i2c->mutex);
}