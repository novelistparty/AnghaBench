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
 int /*<<< orphan*/  dvb_demux_do_ioctl ; 
 int dvb_usercopy (struct inode*,struct file*,unsigned int,unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dvb_demux_ioctl(struct inode *inode, struct file *file,
			    unsigned int cmd, unsigned long arg)
{
	return dvb_usercopy(inode, file, cmd, arg, dvb_demux_do_ioctl);
}