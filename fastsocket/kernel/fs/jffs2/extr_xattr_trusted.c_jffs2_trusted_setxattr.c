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

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  JFFS2_XPREFIX_TRUSTED ; 
 int do_jffs2_setxattr (struct inode*,int /*<<< orphan*/ ,char const*,void const*,size_t,int) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static int jffs2_trusted_setxattr(struct inode *inode, const char *name, const void *buffer,
				  size_t size, int flags)
{
	if (!strcmp(name, ""))
		return -EINVAL;
	return do_jffs2_setxattr(inode, JFFS2_XPREFIX_TRUSTED, name, buffer, size, flags);
}