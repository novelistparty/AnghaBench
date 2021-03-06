#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mfi_disk {int ld_flags; int /*<<< orphan*/  ld_dev; TYPE_1__* ld_controller; } ;
struct TYPE_2__ {scalar_t__ mfi_delete_busy_volumes; int /*<<< orphan*/  mfi_io_lock; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  MA_OWNED ; 
 int MFI_DISK_FLAGS_DISABLED ; 
 int MFI_DISK_FLAGS_OPEN ; 
 int /*<<< orphan*/  device_printf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  mtx_assert (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int
mfi_disk_disable(struct mfi_disk *sc)
{

	mtx_assert(&sc->ld_controller->mfi_io_lock, MA_OWNED);
	if (sc->ld_flags & MFI_DISK_FLAGS_OPEN) {
		if (sc->ld_controller->mfi_delete_busy_volumes)
			return (0);
		device_printf(sc->ld_dev, "Unable to delete busy ld device\n");
		return (EBUSY);
	}
	sc->ld_flags |= MFI_DISK_FLAGS_DISABLED;
	return (0);
}