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
struct TYPE_3__ {int mx; int n; int* mem; } ;
typedef  TYPE_1__ vector ;

/* Variables and functions */
 int* qrealloc (int*,int,int) ; 

void vct_add (vector *v, int x) {
  if (v->mx == v->n) {
    v->mem = qrealloc (v->mem, sizeof (int) * v->mx * 2, sizeof (int) * v->mx);
    v->mx *= 2;
  }
  v->mem[v->n++] = x;
}