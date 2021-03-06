#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_3__ {int /*<<< orphan*/ * dev; } ;
struct TYPE_4__ {int /*<<< orphan*/  rts_pin; int /*<<< orphan*/  cts_pin; TYPE_1__ port; } ;

/* Variables and functions */
 TYPE_2__* bfin_serial_ports ; 
 int /*<<< orphan*/  bfin_serial_reg ; 
 int /*<<< orphan*/  gpio_free (int /*<<< orphan*/ ) ; 
 int nr_active_ports ; 
 int /*<<< orphan*/  uart_remove_one_port (int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static int bfin_serial_remove(struct platform_device *dev)
{
	int i;

	for (i = 0; i < nr_active_ports; i++) {
		if (bfin_serial_ports[i].port.dev != &dev->dev)
			continue;
		uart_remove_one_port(&bfin_serial_reg, &bfin_serial_ports[i].port);
		bfin_serial_ports[i].port.dev = NULL;
#if defined(CONFIG_SERIAL_BFIN_CTSRTS) || \
	defined(CONFIG_SERIAL_BFIN_HARD_CTSRTS)
		gpio_free(bfin_serial_ports[i].cts_pin);
		gpio_free(bfin_serial_ports[i].rts_pin);
#endif
	}

	return 0;
}