#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
struct TYPE_17__ {scalar_t__ fl_end; scalar_t__ fl_start; int /*<<< orphan*/  fl_pid; } ;
struct nlm_lock {TYPE_6__ fl; } ;
struct nlm_file {int /*<<< orphan*/  f_mutex; TYPE_5__* f_file; } ;
struct nlm_block {TYPE_10__* b_call; TYPE_7__* b_file; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_19__ {int /*<<< orphan*/  fl; } ;
struct TYPE_20__ {TYPE_8__ lock; } ;
struct TYPE_18__ {int /*<<< orphan*/  f_file; } ;
struct TYPE_15__ {TYPE_3__* dentry; } ;
struct TYPE_16__ {TYPE_4__ f_path; } ;
struct TYPE_14__ {TYPE_2__* d_inode; } ;
struct TYPE_13__ {int /*<<< orphan*/  i_ino; TYPE_1__* i_sb; } ;
struct TYPE_12__ {int /*<<< orphan*/  s_id; } ;
struct TYPE_11__ {TYPE_9__ a_args; } ;

/* Variables and functions */
 int /*<<< orphan*/  dprintk (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,long long,long long) ; 
 scalar_t__ locks_in_grace () ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nlm_granted ; 
 int /*<<< orphan*/  nlm_lck_denied ; 
 int /*<<< orphan*/  nlm_lck_denied_grace_period ; 
 struct nlm_block* nlmsvc_lookup_block (struct nlm_file*,struct nlm_lock*) ; 
 int /*<<< orphan*/  nlmsvc_release_block (struct nlm_block*) ; 
 int nlmsvc_unlink_block (struct nlm_block*) ; 
 int /*<<< orphan*/  vfs_cancel_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__be32
nlmsvc_cancel_blocked(struct nlm_file *file, struct nlm_lock *lock)
{
	struct nlm_block	*block;
	int status = 0;

	dprintk("lockd: nlmsvc_cancel(%s/%ld, pi=%d, %Ld-%Ld)\n",
				file->f_file->f_path.dentry->d_inode->i_sb->s_id,
				file->f_file->f_path.dentry->d_inode->i_ino,
				lock->fl.fl_pid,
				(long long)lock->fl.fl_start,
				(long long)lock->fl.fl_end);

	if (locks_in_grace())
		return nlm_lck_denied_grace_period;

	mutex_lock(&file->f_mutex);
	block = nlmsvc_lookup_block(file, lock);
	mutex_unlock(&file->f_mutex);
	if (block != NULL) {
		vfs_cancel_lock(block->b_file->f_file,
				&block->b_call->a_args.lock.fl);
		status = nlmsvc_unlink_block(block);
		nlmsvc_release_block(block);
	}
	return status ? nlm_lck_denied : nlm_granted;
}