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
struct bwn_mac {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  bwn_nphy_op_switch_analog (struct bwn_mac*,int) ; 

void
bwn_phy_n_switch_analog(struct bwn_mac *mac, int on)
{
#ifdef	BWN_GPL_PHY
	bwn_nphy_op_switch_analog(mac, on);
#endif
}