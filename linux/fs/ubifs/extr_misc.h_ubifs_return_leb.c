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
struct ubifs_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  LPROPS_NC ; 
 int /*<<< orphan*/  LPROPS_TAKEN ; 
 int ubifs_change_one_lp (struct ubifs_info*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int ubifs_return_leb(struct ubifs_info *c, int lnum)
{
	return ubifs_change_one_lp(c, lnum, LPROPS_NC, LPROPS_NC, 0,
				   LPROPS_TAKEN, 0);
}