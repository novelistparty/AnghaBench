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
struct afs_cb_interest {int /*<<< orphan*/  usage; } ;

/* Variables and functions */
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline struct afs_cb_interest *afs_get_cb_interest(struct afs_cb_interest *cbi)
{
	if (cbi)
		refcount_inc(&cbi->usage);
	return cbi;
}