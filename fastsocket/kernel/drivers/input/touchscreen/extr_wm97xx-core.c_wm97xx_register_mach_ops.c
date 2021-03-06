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
struct wm97xx_mach_ops {int dummy; } ;
struct wm97xx {int /*<<< orphan*/  codec_mutex; struct wm97xx_mach_ops* mach_ops; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 

int wm97xx_register_mach_ops(struct wm97xx *wm,
			     struct wm97xx_mach_ops *mach_ops)
{
	mutex_lock(&wm->codec_mutex);
	if (wm->mach_ops) {
		mutex_unlock(&wm->codec_mutex);
		return -EINVAL;
	}
	wm->mach_ops = mach_ops;
	mutex_unlock(&wm->codec_mutex);

	return 0;
}