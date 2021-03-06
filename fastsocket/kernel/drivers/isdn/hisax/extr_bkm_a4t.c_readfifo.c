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
typedef  int /*<<< orphan*/  u_char ;

/* Variables and functions */
 int /*<<< orphan*/  readreg (unsigned int,unsigned long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
readfifo(unsigned int ale, unsigned long adr, u_char off, u_char * data, int size)
{
	int i;
	for (i = 0; i < size; i++)
		*data++ = readreg(ale, adr, off);
}