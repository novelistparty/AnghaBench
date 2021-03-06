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
typedef  int /*<<< orphan*/  errcode_t ;
typedef  int /*<<< orphan*/  bb_badblocks_list ;

/* Variables and functions */
 int /*<<< orphan*/  make_u64_list (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static errcode_t bb_badblocks_list_create(bb_badblocks_list *ret, int size)
{
	return make_u64_list(size, 0, 0, (bb_badblocks_list *) ret);
}