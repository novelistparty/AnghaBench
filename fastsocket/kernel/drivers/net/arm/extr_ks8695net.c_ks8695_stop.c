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
struct net_device {int dummy; } ;
struct ks8695_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ks8695_shutdown (struct ks8695_priv*) ; 
 struct ks8695_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_off (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 

__attribute__((used)) static int
ks8695_stop(struct net_device *ndev)
{
	struct ks8695_priv *ksp = netdev_priv(ndev);

	netif_stop_queue(ndev);
	netif_carrier_off(ndev);

	ks8695_shutdown(ksp);

	return 0;
}