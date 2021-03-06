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
struct regulator_desc {size_t id; void* fixed_uV; void* uV_step; void* min_uV; } ;
struct regulator_config {struct ltc3676* driver_data; } ;
struct ltc3676 {int /*<<< orphan*/  dev; struct regulator_desc* regulator_descs; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 size_t LTC3676_LDO3 ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 void* ltc3676_scale (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int of_property_read_u32_array (struct device_node*,char*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int ltc3676_of_parse_cb(struct device_node *np,
			       const struct regulator_desc *desc,
			       struct regulator_config *config)
{
	struct ltc3676 *ltc3676 = config->driver_data;
	struct regulator_desc *rdesc = &ltc3676->regulator_descs[desc->id];
	u32 r[2];
	int ret;

	/* LDO3 has a fixed output */
	if (desc->id == LTC3676_LDO3)
		return 0;

	ret = of_property_read_u32_array(np, "lltc,fb-voltage-divider", r, 2);
	if (ret) {
		dev_err(ltc3676->dev, "Failed to parse voltage divider: %d\n",
			ret);
		return ret;
	}

	rdesc->min_uV = ltc3676_scale(desc->min_uV, r[0], r[1]);
	rdesc->uV_step = ltc3676_scale(desc->uV_step, r[0], r[1]);
	rdesc->fixed_uV = ltc3676_scale(desc->fixed_uV, r[0], r[1]);

	return 0;
}