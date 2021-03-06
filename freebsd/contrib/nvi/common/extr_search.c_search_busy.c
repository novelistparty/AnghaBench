#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  busy_t ;
struct TYPE_6__ {TYPE_1__* gp; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* scr_busy ) (TYPE_2__*,char*,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_2__ SCR ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 

void
search_busy(
	SCR *sp,
	busy_t btype)
{
	sp->gp->scr_busy(sp, "078|Searching...", btype);
}