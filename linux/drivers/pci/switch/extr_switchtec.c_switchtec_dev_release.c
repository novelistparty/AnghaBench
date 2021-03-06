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
struct switchtec_user {int dummy; } ;
struct inode {int dummy; } ;
struct file {struct switchtec_user* private_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  stuser_put (struct switchtec_user*) ; 

__attribute__((used)) static int switchtec_dev_release(struct inode *inode, struct file *filp)
{
	struct switchtec_user *stuser = filp->private_data;

	stuser_put(stuser);

	return 0;
}