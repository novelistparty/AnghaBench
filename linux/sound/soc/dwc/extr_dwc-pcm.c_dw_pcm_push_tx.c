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
struct dw_i2s_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  dw_pcm_transfer (struct dw_i2s_dev*,int) ; 

void dw_pcm_push_tx(struct dw_i2s_dev *dev)
{
	dw_pcm_transfer(dev, true);
}