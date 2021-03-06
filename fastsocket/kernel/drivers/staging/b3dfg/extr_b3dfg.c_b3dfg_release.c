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
struct inode {int dummy; } ;
struct file {struct b3dfg_dev* private_data; } ;
struct b3dfg_dev {TYPE_1__* pdev; } ;
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  disable_transmission (struct b3dfg_dev*) ; 

__attribute__((used)) static int b3dfg_release(struct inode *inode, struct file *filp)
{
	struct b3dfg_dev *fgdev = filp->private_data;
	dev_dbg(&fgdev->pdev->dev, "release\n");
	disable_transmission(fgdev);
	return 0;
}