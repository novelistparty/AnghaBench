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
struct cmdnames {unsigned int cnt; int /*<<< orphan*/ * names; int /*<<< orphan*/  alloc; } ;

/* Variables and functions */
 int /*<<< orphan*/  ALLOC_GROW (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void add_cmd_list(struct cmdnames *cmds, struct cmdnames *old)
{
	unsigned int i;

	ALLOC_GROW(cmds->names, cmds->cnt + old->cnt, cmds->alloc);

	for (i = 0; i < old->cnt; i++)
		cmds->names[cmds->cnt++] = old->names[i];
	free(old->names);
	old->cnt = 0;
	old->names = NULL;
}