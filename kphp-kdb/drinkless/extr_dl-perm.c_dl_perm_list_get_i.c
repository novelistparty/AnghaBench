#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int b; int a; struct TYPE_4__* r; } ;
typedef  TYPE_1__ perm_list ;
struct TYPE_5__ {TYPE_1__* v; } ;
typedef  TYPE_2__ dl_perm_list ;

/* Variables and functions */

int dl_perm_list_get_i (dl_perm_list *p, int i) {
/*  if (!(0 <= i && i < p->len)) {
    return -1;
  }*/
  perm_list *v = p->v;
  int t;
  while (i >= (t = v->b - v->a)) {
    i -= t;
    v = v->r;
  }
  return v->a + i;
}