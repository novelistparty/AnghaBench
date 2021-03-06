#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uma_zone_t ;
typedef  TYPE_1__* uma_keg_t ;
struct TYPE_5__ {int uk_reserve; } ;

/* Variables and functions */
 int /*<<< orphan*/  KEG_GET (int /*<<< orphan*/ ,TYPE_1__*) ; 
 int /*<<< orphan*/  KEG_LOCK (TYPE_1__*) ; 
 int /*<<< orphan*/  KEG_UNLOCK (TYPE_1__*) ; 

void
uma_zone_reserve(uma_zone_t zone, int items)
{
	uma_keg_t keg;

	KEG_GET(zone, keg);
	KEG_LOCK(keg);
	keg->uk_reserve = items;
	KEG_UNLOCK(keg);
}