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
typedef  int /*<<< orphan*/  u8 ;
struct acpi_smb_hc {int dummy; } ;

/* Variables and functions */
 int acpi_smbus_transaction (struct acpi_smb_hc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int acpi_smbus_write(struct acpi_smb_hc *hc, u8 protocol, u8 address,
		     u8 command, u8 *data, u8 length)
{
	return acpi_smbus_transaction(hc, protocol, address, command, data, length);
}