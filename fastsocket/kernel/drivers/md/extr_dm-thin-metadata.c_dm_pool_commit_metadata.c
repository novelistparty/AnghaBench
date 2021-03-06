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
struct dm_pool_metadata {int /*<<< orphan*/  root_lock; scalar_t__ fail_io; } ;

/* Variables and functions */
 int EINVAL ; 
 int __begin_transaction (struct dm_pool_metadata*) ; 
 int __commit_transaction (struct dm_pool_metadata*) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 

int dm_pool_commit_metadata(struct dm_pool_metadata *pmd)
{
	int r = -EINVAL;

	down_write(&pmd->root_lock);
	if (pmd->fail_io)
		goto out;

	r = __commit_transaction(pmd);
	if (r <= 0)
		goto out;

	/*
	 * Open the next transaction.
	 */
	r = __begin_transaction(pmd);
out:
	up_write(&pmd->root_lock);
	return r;
}