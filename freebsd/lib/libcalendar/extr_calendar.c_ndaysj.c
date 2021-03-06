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
typedef  int /*<<< orphan*/  date ;

/* Variables and functions */
 int /*<<< orphan*/ * date2idt (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int ndaysji (int /*<<< orphan*/ *) ; 

int
ndaysj(date *dt)
{
	date    idt;		/* Internal date representation */

	if (date2idt(&idt, dt) == NULL)
		return (-1);
	else
		return (ndaysji(&idt));
}