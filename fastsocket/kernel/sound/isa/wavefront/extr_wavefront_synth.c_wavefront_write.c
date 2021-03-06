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
struct TYPE_4__ {int /*<<< orphan*/  data_port; } ;
typedef  TYPE_1__ snd_wavefront_t ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  STAT_CAN_WRITE ; 
 int /*<<< orphan*/  WF_DEBUG_DATA ; 
 int /*<<< orphan*/  outb (unsigned char,int /*<<< orphan*/ ) ; 
 scalar_t__ wavefront_wait (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int
wavefront_write (snd_wavefront_t *dev, unsigned char data)

{
	if (wavefront_wait (dev, STAT_CAN_WRITE)) {
		outb (data, dev->data_port);
		return 0;
	}

	DPRINT (WF_DEBUG_DATA, "write timeout.\n");

	return -1;
}