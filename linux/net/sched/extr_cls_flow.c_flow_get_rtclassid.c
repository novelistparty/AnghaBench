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
typedef  int /*<<< orphan*/  u32 ;
struct sk_buff {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  tclassid; } ;

/* Variables and functions */
 TYPE_1__* skb_dst (struct sk_buff const*) ; 

__attribute__((used)) static u32 flow_get_rtclassid(const struct sk_buff *skb)
{
#ifdef CONFIG_IP_ROUTE_CLASSID
	if (skb_dst(skb))
		return skb_dst(skb)->tclassid;
#endif
	return 0;
}