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
struct autofs_dev_ioctl {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct autofs_dev_ioctl*) ; 

__attribute__((used)) static inline void free_dev_ioctl(struct autofs_dev_ioctl *param)
{
	kfree(param);
	return;
}