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
typedef  int /*<<< orphan*/  each_ref_fn ;

/* Variables and functions */
 int /*<<< orphan*/  get_submodule_ref_store (char const*) ; 
 int refs_for_each_remote_ref (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 

__attribute__((used)) static int for_each_remote_ref_submodule(const char *submodule,
					 each_ref_fn fn, void *cb_data)
{
	return refs_for_each_remote_ref(get_submodule_ref_store(submodule),
					fn, cb_data);
}