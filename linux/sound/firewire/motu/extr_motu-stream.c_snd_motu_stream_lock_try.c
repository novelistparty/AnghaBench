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
struct snd_motu {scalar_t__ dev_lock_count; int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  motu_lock_changed (struct snd_motu*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

int snd_motu_stream_lock_try(struct snd_motu *motu)
{
	int err;

	spin_lock_irq(&motu->lock);

	if (motu->dev_lock_count < 0) {
		err = -EBUSY;
		goto out;
	}

	if (motu->dev_lock_count++ == 0)
		motu_lock_changed(motu);
	err = 0;
out:
	spin_unlock_irq(&motu->lock);
	return err;
}