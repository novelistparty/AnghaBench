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
struct cpu_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ST (int) ; 
 int /*<<< orphan*/  fpush (int /*<<< orphan*/ ) ; 

void fpu_ld(struct cpu_state *cpu, int i) {
    fpush(ST(i));
}