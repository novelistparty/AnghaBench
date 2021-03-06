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
struct list_entry {int /*<<< orphan*/  next; } ;

/* Variables and functions */
 int /*<<< orphan*/  list_add (struct list_entry*,struct list_entry*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void list_add_head(
    struct list_entry *head,
    struct list_entry *entry)
{
    list_add(entry, head, head->next);
}