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

/* Variables and functions */
 int /*<<< orphan*/  outb (unsigned char,scalar_t__) ; 
 scalar_t__ pas_translate_code ; 

void pas_write(unsigned char data, int ioaddr)
{
	outb((data), ioaddr + pas_translate_code);
}