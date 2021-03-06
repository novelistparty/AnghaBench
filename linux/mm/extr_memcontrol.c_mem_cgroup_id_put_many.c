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
struct TYPE_2__ {int /*<<< orphan*/  ref; } ;
struct mem_cgroup {int /*<<< orphan*/  css; TYPE_1__ id; } ;

/* Variables and functions */
 int /*<<< orphan*/  css_put (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mem_cgroup_id_remove (struct mem_cgroup*) ; 
 scalar_t__ refcount_sub_and_test (unsigned int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mem_cgroup_id_put_many(struct mem_cgroup *memcg, unsigned int n)
{
	if (refcount_sub_and_test(n, &memcg->id.ref)) {
		mem_cgroup_id_remove(memcg);

		/* Memcg ID pins CSS */
		css_put(&memcg->css);
	}
}