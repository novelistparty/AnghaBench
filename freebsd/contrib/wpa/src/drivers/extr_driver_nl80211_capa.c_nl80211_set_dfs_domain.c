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
typedef  scalar_t__ u8 ;
typedef  enum nl80211_dfs_regions { ____Placeholder_nl80211_dfs_regions } nl80211_dfs_regions ;

/* Variables and functions */
 scalar_t__ HOSTAPD_DFS_REGION_ETSI ; 
 scalar_t__ HOSTAPD_DFS_REGION_FCC ; 
 scalar_t__ HOSTAPD_DFS_REGION_JP ; 
 int NL80211_DFS_ETSI ; 
 int NL80211_DFS_FCC ; 
 int NL80211_DFS_JP ; 

__attribute__((used)) static void nl80211_set_dfs_domain(enum nl80211_dfs_regions region,
				   u8 *dfs_domain)
{
	if (region == NL80211_DFS_FCC)
		*dfs_domain = HOSTAPD_DFS_REGION_FCC;
	else if (region == NL80211_DFS_ETSI)
		*dfs_domain = HOSTAPD_DFS_REGION_ETSI;
	else if (region == NL80211_DFS_JP)
		*dfs_domain = HOSTAPD_DFS_REGION_JP;
	else
		*dfs_domain = 0;
}