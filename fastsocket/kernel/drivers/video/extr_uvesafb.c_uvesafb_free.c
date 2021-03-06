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
struct uvesafb_ktask {struct uvesafb_ktask* done; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct uvesafb_ktask*) ; 

__attribute__((used)) static void uvesafb_free(struct uvesafb_ktask *task)
{
	if (task) {
		if (task->done)
			kfree(task->done);
		kfree(task);
	}
}