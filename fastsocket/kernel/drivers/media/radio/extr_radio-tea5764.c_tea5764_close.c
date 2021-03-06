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
struct tea5764_device {int /*<<< orphan*/  mutex; int /*<<< orphan*/  users; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct tea5764_device* video_drvdata (struct file*) ; 

__attribute__((used)) static int tea5764_close(struct file *file)
{
	struct tea5764_device *radio = video_drvdata(file);

	if (!radio)
		return -ENODEV;
	mutex_lock(&radio->mutex);
	radio->users--;
	mutex_unlock(&radio->mutex);
	return 0;
}