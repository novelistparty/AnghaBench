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
typedef  union iwreq_data {int dummy; } iwreq_data ;
struct r8180_priv {int /*<<< orphan*/  wx_sem; TYPE_1__* ieee80211; scalar_t__ bInactivePs; } ;
struct net_device {int dummy; } ;
struct iw_request_info {int dummy; } ;
struct TYPE_2__ {scalar_t__ bHwRadioOff; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPSLeave (struct net_device*) ; 
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 struct r8180_priv* ieee80211_priv (struct net_device*) ; 
 int ieee80211_wx_set_essid (TYPE_1__*,struct iw_request_info*,union iwreq_data*,char*) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int r8180_wx_set_essid(struct net_device *dev,
			      struct iw_request_info *a,
			      union iwreq_data *wrqu, char *b)
{
	struct r8180_priv *priv = ieee80211_priv(dev);

	int ret;

	if(priv->ieee80211->bHwRadioOff)
		return 0;

	down(&priv->wx_sem);
	//printk("set essid ENABLE_IPS\n");
	if(priv->bInactivePs)
		IPSLeave(dev);
//	printk("haha:set essid %s essid_len = %d essid_flgs = %d\n",b,  wrqu->essid.length, wrqu->essid.flags);

	ret = ieee80211_wx_set_essid(priv->ieee80211,a,wrqu,b);

	up(&priv->wx_sem);
	return ret;
}