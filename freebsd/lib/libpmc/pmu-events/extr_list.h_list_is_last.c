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
struct list_head {struct list_head const* next; } ;

/* Variables and functions */

__attribute__((used)) static inline int list_is_last(const struct list_head *list,
				const struct list_head *head)
{
	return list->next == head;
}