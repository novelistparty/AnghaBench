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
struct TYPE_2__ {int /*<<< orphan*/  path; } ;
typedef  TYPE_1__ git_index_entry ;

/* Variables and functions */
 int strcasecmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int git_diff__entry_icmp(const void *a, const void *b)
{
	const git_index_entry *entry_a = a;
	const git_index_entry *entry_b = b;

	return strcasecmp(entry_a->path, entry_b->path);
}