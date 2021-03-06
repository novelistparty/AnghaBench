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
struct TYPE_2__ {int initialized; int /*<<< orphan*/  wq; } ;
struct host1x_cdma {TYPE_1__ timeout; } ;

/* Variables and functions */
 int /*<<< orphan*/  cancel_delayed_work (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void cdma_timeout_destroy(struct host1x_cdma *cdma)
{
	if (cdma->timeout.initialized)
		cancel_delayed_work(&cdma->timeout.wq);

	cdma->timeout.initialized = false;
}