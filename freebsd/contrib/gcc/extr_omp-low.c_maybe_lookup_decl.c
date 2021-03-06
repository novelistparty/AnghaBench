#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ tree ;
typedef  TYPE_2__* splay_tree_node ;
typedef  int /*<<< orphan*/  splay_tree_key ;
struct TYPE_6__ {int /*<<< orphan*/  decl_map; } ;
struct TYPE_8__ {TYPE_1__ cb; } ;
typedef  TYPE_3__ omp_context ;
struct TYPE_7__ {scalar_t__ value; } ;

/* Variables and functions */
 scalar_t__ NULL_TREE ; 
 TYPE_2__* splay_tree_lookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline tree
maybe_lookup_decl (tree var, omp_context *ctx)
{
  splay_tree_node n;
  n = splay_tree_lookup (ctx->cb.decl_map, (splay_tree_key) var);
  return n ? (tree) n->value : NULL_TREE;
}