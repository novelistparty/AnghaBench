#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/ * device_t ;
typedef  TYPE_1__* devclass_t ;
struct TYPE_3__ {int /*<<< orphan*/ ** dev_list; } ;

/* Variables and functions */
 int DEVCLASS_MAXUNIT ; 

device_t
devclass_get_device(devclass_t dc, int unit)
{
	return (((unit < 0) || (unit >= DEVCLASS_MAXUNIT) || (dc == NULL)) ?
	    NULL : dc->dev_list[unit]);
}