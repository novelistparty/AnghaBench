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
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PDE_DATA (struct inode*) ; 
 int /*<<< orphan*/  proc_scsi_show ; 
 int single_open_size (struct file*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int proc_scsi_host_open(struct inode *inode, struct file *file)
{
	return single_open_size(file, proc_scsi_show, PDE_DATA(inode),
				4 * PAGE_SIZE);
}