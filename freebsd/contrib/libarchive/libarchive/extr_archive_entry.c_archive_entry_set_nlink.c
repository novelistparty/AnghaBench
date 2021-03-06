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
struct TYPE_2__ {unsigned int aest_nlink; } ;
struct archive_entry {TYPE_1__ ae_stat; scalar_t__ stat_valid; } ;

/* Variables and functions */

void
archive_entry_set_nlink(struct archive_entry *entry, unsigned int nlink)
{
	entry->stat_valid = 0;
	entry->ae_stat.aest_nlink = nlink;
}