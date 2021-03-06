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
struct phonet_device_list {int dummy; } ;
struct phonet_net {struct phonet_device_list pndevs; } ;
struct net {int dummy; } ;

/* Variables and functions */
 struct phonet_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phonet_net_id ; 

struct phonet_device_list *phonet_device_list(struct net *net)
{
	struct phonet_net *pnn = net_generic(net, phonet_net_id);
	return &pnn->pndevs;
}