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
typedef  scalar_t__ u_long ;
typedef  int /*<<< orphan*/  portdev_t ;

/* Variables and functions */
 char* iMajorError ; 
 char* iMinorError ; 
 scalar_t__ major_8_8 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  makedev_8_8 (scalar_t__,scalar_t__) ; 
 scalar_t__ minor_8_8 (int /*<<< orphan*/ ) ; 
 char* tooManyFields ; 

__attribute__((used)) static portdev_t
pack_8_8(int n, u_long numbers[], const char **error)
{
	portdev_t dev = 0;

	if (n == 2) {
		dev = makedev_8_8(numbers[0], numbers[1]);
		if ((u_long)major_8_8(dev) != numbers[0])
			*error = iMajorError;
		if ((u_long)minor_8_8(dev) != numbers[1])
			*error = iMinorError;
	} else
		*error = tooManyFields;
	return (dev);
}