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
 double SLOT_MULT ; 
 double cpu2slot (int) ; 

__attribute__((used)) static double cpu2y(int cpu)
{
	return cpu2slot(cpu) * SLOT_MULT;
}