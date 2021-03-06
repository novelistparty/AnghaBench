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
struct ata_port {int dummy; } ;
struct ata_device {int /*<<< orphan*/  pio_mode; } ;

/* Variables and functions */
 int /*<<< orphan*/  hpt366_set_mode (struct ata_port*,struct ata_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hpt366_set_piomode(struct ata_port *ap, struct ata_device *adev)
{
	hpt366_set_mode(ap, adev, adev->pio_mode);
}