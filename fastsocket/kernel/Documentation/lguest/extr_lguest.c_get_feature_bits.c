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
struct lguest_vqconfig {int dummy; } ;
struct device {int num_vq; scalar_t__ desc; } ;

/* Variables and functions */

__attribute__((used)) static u8 *get_feature_bits(struct device *dev)
{
	return (u8 *)(dev->desc + 1)
		+ dev->num_vq * sizeof(struct lguest_vqconfig);
}