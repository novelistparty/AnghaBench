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
typedef  int /*<<< orphan*/  ecard_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXPMASK_ENABLE ; 
 int /*<<< orphan*/  __raw_writeb (int,int /*<<< orphan*/ ) ; 
 int have_expmask ; 

__attribute__((used)) static void ecard_def_irq_enable(ecard_t *ec, int irqnr)
{
#ifdef HAS_EXPMASK
	if (irqnr < 4 && have_expmask) {
		have_expmask |= 1 << irqnr;
		__raw_writeb(have_expmask, EXPMASK_ENABLE);
	}
#endif
}