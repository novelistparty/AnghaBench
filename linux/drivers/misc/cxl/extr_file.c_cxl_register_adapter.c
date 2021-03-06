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
struct TYPE_2__ {int /*<<< orphan*/  class; } ;
struct cxl {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  cxl_class ; 
 int device_register (TYPE_1__*) ; 

int cxl_register_adapter(struct cxl *adapter)
{
	adapter->dev.class = cxl_class;

	/*
	 * Future: When we support dynamically reprogramming the PSL & AFU we
	 * will expose the interface to do that via a chardev:
	 * adapter->dev.devt = CXL_CARD_MKDEV(adapter);
	 */

	return device_register(&adapter->dev);
}