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
struct seq_file {int dummy; } ;
typedef  int /*<<< orphan*/  pgd_t ;

/* Variables and functions */
 int /*<<< orphan*/  ptdump_walk_pgd_level_core (struct seq_file*,int /*<<< orphan*/ *,int,int) ; 

void ptdump_walk_pgd_level(struct seq_file *m, pgd_t *pgd)
{
	ptdump_walk_pgd_level_core(m, pgd, false, true);
}