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
struct hiddev_list {int /*<<< orphan*/  fasync; } ;
struct file {struct hiddev_list* private_data; } ;

/* Variables and functions */
 int fasync_helper (int,struct file*,int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int hiddev_fasync(int fd, struct file *file, int on)
{
	struct hiddev_list *list = file->private_data;

	return fasync_helper(fd, file, on, &list->fasync);
}