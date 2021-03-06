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
struct ifnet {int /*<<< orphan*/  if_qflush; } ;
typedef  scalar_t__ if_t ;
typedef  int /*<<< orphan*/  if_qflush_fn_t ;

/* Variables and functions */

void if_setqflushfn(if_t ifp, if_qflush_fn_t flush_fn)
{
	((struct ifnet *)ifp)->if_qflush = flush_fn;
	
}