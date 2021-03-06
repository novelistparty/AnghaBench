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
typedef  int /*<<< orphan*/  uint16_t ;
struct cpu_state {int /*<<< orphan*/  rc; int /*<<< orphan*/  fcw; } ;

/* Variables and functions */
 int /*<<< orphan*/  f80_rounding_mode ; 

void fpu_ldcw16(struct cpu_state *cpu, uint16_t *i) {
    cpu->fcw = *i;
    f80_rounding_mode = cpu->rc;
}