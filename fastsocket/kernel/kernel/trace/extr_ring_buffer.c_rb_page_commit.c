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
struct buffer_page {TYPE_1__* page; } ;
struct TYPE_2__ {int /*<<< orphan*/  commit; } ;

/* Variables and functions */
 int local_read (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline unsigned rb_page_commit(struct buffer_page *bpage)
{
	return local_read(&bpage->page->commit);
}