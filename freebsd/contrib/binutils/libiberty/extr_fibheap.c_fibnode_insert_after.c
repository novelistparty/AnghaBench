#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* fibnode_t ;
struct TYPE_4__ {struct TYPE_4__* left; struct TYPE_4__* right; } ;

/* Variables and functions */

__attribute__((used)) static void
fibnode_insert_after (fibnode_t a, fibnode_t b)
{
  if (a == a->right)
    {
      a->right = b;
      a->left = b;
      b->right = a;
      b->left = a;
    }
  else
    {
      b->right = a->right;
      a->right->left = b;
      a->right = b;
      b->left = a;
    }
}