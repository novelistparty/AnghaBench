#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct seq_file {int /*<<< orphan*/  file; } ;
typedef  int /*<<< orphan*/  loff_t ;
struct TYPE_3__ {int /*<<< orphan*/  hostap_interfaces; int /*<<< orphan*/  iface_lock; } ;
typedef  TYPE_1__ local_info_t ;

/* Variables and functions */
 TYPE_1__* PDE_DATA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  file_inode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  read_lock_bh (int /*<<< orphan*/ *) ; 
 void* seq_list_start (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void *prism2_wds_proc_start(struct seq_file *m, loff_t *_pos)
{
	local_info_t *local = PDE_DATA(file_inode(m->file));
	read_lock_bh(&local->iface_lock);
	return seq_list_start(&local->hostap_interfaces, *_pos);
}