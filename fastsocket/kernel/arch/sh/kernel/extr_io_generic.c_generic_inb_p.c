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
typedef  unsigned long u8 ;

/* Variables and functions */
 int /*<<< orphan*/  ctrl_delay () ; 
 unsigned long generic_inb (unsigned long) ; 

u8 generic_inb_p(unsigned long port)
{
	unsigned long v = generic_inb(port);

	ctrl_delay();
	return v;
}