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
struct libusb20_transfer {int dummy; } ;

/* Variables and functions */
#define  LIBUSB20_TRANSFER_START 128 
 int libusb20_tr_get_status (struct libusb20_transfer*) ; 
 int /*<<< orphan*/  libusb20_tr_submit (struct libusb20_transfer*) ; 

__attribute__((used)) static void
dummy_callback(struct libusb20_transfer *xfer)
{
	;				/* style fix */
	switch (libusb20_tr_get_status(xfer)) {
	case LIBUSB20_TRANSFER_START:
		libusb20_tr_submit(xfer);
		break;
	default:
		/* complete or error */
		break;
	}
	return;
}