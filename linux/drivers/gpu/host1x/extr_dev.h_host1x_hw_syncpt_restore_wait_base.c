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
struct host1x_syncpt {int dummy; } ;
struct host1x {TYPE_1__* syncpt_op; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* restore_wait_base ) (struct host1x_syncpt*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct host1x_syncpt*) ; 

__attribute__((used)) static inline void host1x_hw_syncpt_restore_wait_base(struct host1x *host,
						      struct host1x_syncpt *sp)
{
	host->syncpt_op->restore_wait_base(sp);
}