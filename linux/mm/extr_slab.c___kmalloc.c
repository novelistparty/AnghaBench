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
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 int /*<<< orphan*/  _RET_IP_ ; 
 void* __do_kmalloc (size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void *__kmalloc(size_t size, gfp_t flags)
{
	return __do_kmalloc(size, flags, _RET_IP_);
}