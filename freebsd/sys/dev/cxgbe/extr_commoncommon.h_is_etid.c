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
typedef  scalar_t__ u_int ;
struct TYPE_2__ {scalar_t__ netids; scalar_t__ etid_base; scalar_t__ etid_end; } ;
struct adapter {TYPE_1__ tids; } ;

/* Variables and functions */

__attribute__((used)) static inline int is_etid(const struct adapter *sc, u_int tid)
{

	return (sc->tids.netids > 0 && tid >= sc->tids.etid_base &&
	    tid <= sc->tids.etid_end);
}