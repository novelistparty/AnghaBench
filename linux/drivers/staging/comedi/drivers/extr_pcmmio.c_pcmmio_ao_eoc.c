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
struct comedi_subdevice {int dummy; } ;
struct comedi_insn {int dummy; } ;
struct comedi_device {scalar_t__ iobase; } ;

/* Variables and functions */
 int EBUSY ; 
 unsigned char PCMMIO_AO_STATUS_DATA_READY ; 
 scalar_t__ PCMMIO_AO_STATUS_REG ; 
 unsigned char inb (scalar_t__) ; 

__attribute__((used)) static int pcmmio_ao_eoc(struct comedi_device *dev,
			 struct comedi_subdevice *s,
			 struct comedi_insn *insn,
			 unsigned long context)
{
	unsigned char status;

	status = inb(dev->iobase + PCMMIO_AO_STATUS_REG);
	if (status & PCMMIO_AO_STATUS_DATA_READY)
		return 0;
	return -EBUSY;
}