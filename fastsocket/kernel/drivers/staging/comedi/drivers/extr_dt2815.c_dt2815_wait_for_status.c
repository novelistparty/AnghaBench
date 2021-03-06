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
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
 scalar_t__ DT2815_STATUS ; 
 int inb (scalar_t__) ; 

__attribute__((used)) static int dt2815_wait_for_status(struct comedi_device *dev, int status)
{
	int i;

	for (i = 0; i < 100; i++) {
		if (inb(dev->iobase + DT2815_STATUS) == status)
			break;
	}
	return status;
}