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
struct usb_fifo {int dummy; } ;
struct uhid_softc {int sc_flags; int /*<<< orphan*/ * sc_xfer; } ;

/* Variables and functions */
 size_t UHID_CTRL_DT_RD ; 
 int UHID_FLAG_IMMED ; 
 size_t UHID_INTR_DT_RD ; 
 struct uhid_softc* usb_fifo_softc (struct usb_fifo*) ; 
 int /*<<< orphan*/  usbd_transfer_start (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
uhid_start_read(struct usb_fifo *fifo)
{
	struct uhid_softc *sc = usb_fifo_softc(fifo);

	if (sc->sc_flags & UHID_FLAG_IMMED) {
		usbd_transfer_start(sc->sc_xfer[UHID_CTRL_DT_RD]);
	} else {
		usbd_transfer_start(sc->sc_xfer[UHID_INTR_DT_RD]);
	}
}