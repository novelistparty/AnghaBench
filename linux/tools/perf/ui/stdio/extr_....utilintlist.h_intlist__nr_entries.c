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
struct intlist {int /*<<< orphan*/  rblist; } ;

/* Variables and functions */
 unsigned int rblist__nr_entries (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned int intlist__nr_entries(const struct intlist *ilist)
{
	return rblist__nr_entries(&ilist->rblist);
}