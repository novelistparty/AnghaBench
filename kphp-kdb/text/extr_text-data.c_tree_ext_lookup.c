#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int x; struct TYPE_5__* right; struct TYPE_5__* left; } ;
typedef  TYPE_1__ tree_ext_t ;

/* Variables and functions */
 TYPE_1__* NIL ; 

__attribute__((used)) static inline tree_ext_t *tree_ext_lookup (tree_ext_t *T, int x) {
  while (T != NIL && x != T->x) {
    T = (x < T->x) ? T->left : T->right;
  }
  return T;
}