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
struct ubifs_info {int /*<<< orphan*/  nhead_offs; int /*<<< orphan*/  nhead_lnum; int /*<<< orphan*/  ihead_offs; int /*<<< orphan*/  ihead_lnum; scalar_t__ remounting_rw; TYPE_1__* vfs_sb; } ;
struct TYPE_2__ {int s_flags; } ;

/* Variables and functions */
 int MS_RDONLY ; 
 int /*<<< orphan*/  dbg_rcvry (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int recover_head (struct ubifs_info const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  ubifs_assert (int) ; 

int ubifs_recover_inl_heads(const struct ubifs_info *c, void *sbuf)
{
	int err;

	ubifs_assert(!(c->vfs_sb->s_flags & MS_RDONLY) || c->remounting_rw);

	dbg_rcvry("checking index head at %d:%d", c->ihead_lnum, c->ihead_offs);
	err = recover_head(c, c->ihead_lnum, c->ihead_offs, sbuf);
	if (err)
		return err;

	dbg_rcvry("checking LPT head at %d:%d", c->nhead_lnum, c->nhead_offs);
	err = recover_head(c, c->nhead_lnum, c->nhead_offs, sbuf);
	if (err)
		return err;

	return 0;
}