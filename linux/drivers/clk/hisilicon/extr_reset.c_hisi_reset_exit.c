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
struct hisi_reset_controller {int /*<<< orphan*/  rcdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  reset_controller_unregister (int /*<<< orphan*/ *) ; 

void hisi_reset_exit(struct hisi_reset_controller *rstc)
{
	reset_controller_unregister(&rstc->rcdev);
}