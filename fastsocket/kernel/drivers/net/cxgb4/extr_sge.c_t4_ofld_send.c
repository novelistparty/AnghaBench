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
struct sk_buff {int dummy; } ;
struct adapter {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  local_bh_disable () ; 
 int /*<<< orphan*/  local_bh_enable () ; 
 int ofld_send (struct adapter*,struct sk_buff*) ; 

int t4_ofld_send(struct adapter *adap, struct sk_buff *skb)
{
	int ret;

	local_bh_disable();
	ret = ofld_send(adap, skb);
	local_bh_enable();
	return ret;
}