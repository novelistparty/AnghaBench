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
struct t3cdev {int dummy; } ;
struct adapter {int /*<<< orphan*/  open_device_map; } ;

/* Variables and functions */
 int /*<<< orphan*/  OFFLOAD_DEVMAP_BIT ; 
 struct adapter* tdev2adap (struct t3cdev*) ; 
 int test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int offload_activated(struct t3cdev *tdev)
{
	const struct adapter *adapter = tdev2adap(tdev);

	return test_bit(OFFLOAD_DEVMAP_BIT, &adapter->open_device_map);
}