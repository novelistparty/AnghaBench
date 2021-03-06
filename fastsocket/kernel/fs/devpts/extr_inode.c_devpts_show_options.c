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
struct vfsmount {int /*<<< orphan*/  mnt_sb; } ;
struct seq_file {int dummy; } ;
struct pts_mount_opts {int /*<<< orphan*/  ptmxmode; int /*<<< orphan*/  mode; int /*<<< orphan*/  gid; scalar_t__ setgid; int /*<<< orphan*/  uid; scalar_t__ setuid; } ;
struct pts_fs_info {struct pts_mount_opts mount_opts; } ;

/* Variables and functions */
 struct pts_fs_info* DEVPTS_SB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int devpts_show_options(struct seq_file *seq, struct vfsmount *vfs)
{
	struct pts_fs_info *fsi = DEVPTS_SB(vfs->mnt_sb);
	struct pts_mount_opts *opts = &fsi->mount_opts;

	if (opts->setuid)
		seq_printf(seq, ",uid=%u", opts->uid);
	if (opts->setgid)
		seq_printf(seq, ",gid=%u", opts->gid);
	seq_printf(seq, ",mode=%03o", opts->mode);
#ifdef CONFIG_DEVPTS_MULTIPLE_INSTANCES
	seq_printf(seq, ",ptmxmode=%03o", opts->ptmxmode);
#endif

	return 0;
}