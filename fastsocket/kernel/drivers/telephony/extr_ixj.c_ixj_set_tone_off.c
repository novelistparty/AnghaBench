#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {unsigned short tone_off_time; } ;
typedef  TYPE_1__ IXJ ;

/* Variables and functions */
 scalar_t__ ixj_WriteDSPCommand (unsigned short,TYPE_1__*) ; 

__attribute__((used)) static int ixj_set_tone_off(unsigned short arg, IXJ *j)
{
	j->tone_off_time = arg;
	if (ixj_WriteDSPCommand(0x6E05, j))		/* Set Tone Off Period */

		return -1;
	if (ixj_WriteDSPCommand(arg, j))
		return -1;
	return 0;
}