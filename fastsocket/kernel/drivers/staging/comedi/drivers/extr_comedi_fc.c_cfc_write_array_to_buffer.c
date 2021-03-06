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
struct comedi_subdevice {struct comedi_async* async; } ;
struct comedi_async {int /*<<< orphan*/  events; } ;

/* Variables and functions */
 int /*<<< orphan*/  COMEDI_CB_BLOCK ; 
 int /*<<< orphan*/  COMEDI_CB_OVERFLOW ; 
 int /*<<< orphan*/  comedi_buf_memcpy_to (struct comedi_async*,int /*<<< orphan*/ ,void*,unsigned int) ; 
 unsigned int comedi_buf_write_alloc (struct comedi_async*,unsigned int) ; 
 int /*<<< orphan*/  comedi_buf_write_free (struct comedi_async*,unsigned int) ; 
 int /*<<< orphan*/  increment_scan_progress (struct comedi_subdevice*,unsigned int) ; 
 int /*<<< orphan*/  printk (char*) ; 

unsigned int cfc_write_array_to_buffer(struct comedi_subdevice *subd,
				       void *data, unsigned int num_bytes)
{
	struct comedi_async *async = subd->async;
	unsigned int retval;

	if (num_bytes == 0)
		return 0;

	retval = comedi_buf_write_alloc(async, num_bytes);
	if (retval != num_bytes) {
		printk("comedi: buffer overrun\n");
		async->events |= COMEDI_CB_OVERFLOW;
		return 0;
	}

	comedi_buf_memcpy_to(async, 0, data, num_bytes);
	comedi_buf_write_free(async, num_bytes);
	increment_scan_progress(subd, num_bytes);
	async->events |= COMEDI_CB_BLOCK;

	return num_bytes;
}