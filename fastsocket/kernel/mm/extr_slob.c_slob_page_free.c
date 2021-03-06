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
struct slob_page {int dummy; } ;
struct page {int dummy; } ;

/* Variables and functions */
 int PageSlobFree (struct page*) ; 

__attribute__((used)) static inline int slob_page_free(struct slob_page *sp)
{
	return PageSlobFree((struct page *)sp);
}