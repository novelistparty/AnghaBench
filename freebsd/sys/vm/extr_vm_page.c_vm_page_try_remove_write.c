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
typedef  int /*<<< orphan*/  vm_page_t ;

/* Variables and functions */
 int /*<<< orphan*/  pmap_remove_write ; 
 int vm_page_try_blocked_op (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool
vm_page_try_remove_write(vm_page_t m)
{

	return (vm_page_try_blocked_op(m, pmap_remove_write));
}