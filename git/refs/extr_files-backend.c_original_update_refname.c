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
struct ref_update {char const* refname; struct ref_update* parent_update; } ;

/* Variables and functions */

__attribute__((used)) static const char *original_update_refname(struct ref_update *update)
{
	while (update->parent_update)
		update = update->parent_update;

	return update->refname;
}