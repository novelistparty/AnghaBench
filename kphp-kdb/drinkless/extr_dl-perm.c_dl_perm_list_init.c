#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  v; scalar_t__ len; scalar_t__ n; } ;
typedef  TYPE_1__ dl_perm_list ;

/* Variables and functions */
 int /*<<< orphan*/  list_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void dl_perm_list_init (dl_perm_list *p) {
  p->n = 0;
  p->len = 0;
  p->v = list_alloc (0, 0);
}