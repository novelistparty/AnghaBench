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
typedef  int /*<<< orphan*/  trp_node ;
struct TYPE_3__ {int /*<<< orphan*/ * r; struct TYPE_3__* l; } ;

/* Variables and functions */
 int allocated_nodes_cnt ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__* free_nodes ; 
 scalar_t__ free_nodes_cnt ; 
 TYPE_1__* qmalloc (int) ; 

void trp_init_mem (int n) {
  assert (free_nodes_cnt == 0);
  assert (n > 0);

  free_nodes = qmalloc (sizeof (trp_node) * n);
  assert (free_nodes != NULL);

  allocated_nodes_cnt += n;
  free_nodes_cnt += n;

  int i;
  for (i = 0; i + 1 < n; i++) {
    free_nodes[i].l = &free_nodes[i + 1];
    free_nodes[i].r = NULL;
  }
  free_nodes[n - 1].l = free_nodes[n - 1].r = NULL;
}