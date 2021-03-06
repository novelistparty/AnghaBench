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
struct TYPE_2__ {int /*<<< orphan*/  max_entries; } ;
struct btree_node {void* keys; TYPE_1__ header; } ;

/* Variables and functions */
 size_t le32_to_cpu (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void *value_base(struct btree_node *n)
{
	return &n->keys[le32_to_cpu(n->header.max_entries)];
}