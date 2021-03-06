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
typedef  scalar_t__ uint32_t ;
struct TYPE_5__ {int* ftp_argmap; int /*<<< orphan*/  ftp_nargs; } ;
typedef  TYPE_1__ fasttrap_probe_t ;
struct TYPE_6__ {scalar_t__ sp; scalar_t__* r; } ;
typedef  TYPE_2__ arm_saved_state_t ;

/* Variables and functions */
 int MIN (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fasttrap_fuword32_noerr (scalar_t__,scalar_t__*) ; 

__attribute__((used)) static void
fasttrap_usdt_args(fasttrap_probe_t *probe, arm_saved_state_t *regs, int argc,
    uint32_t *argv)
{
	int i, x, cap = MIN(argc, probe->ftp_nargs);

	for (i = 0; i < cap; i++) {
		x = probe->ftp_argmap[i];

		if (x < 4) {
			argv[i] = regs->r[x];
		} else {
			fasttrap_fuword32_noerr(regs->sp + (x - 4) * sizeof(uint32_t), &argv[i]);
		}
	}

	for (; i < argc; i++) {
		argv[i] = 0;
	}
}