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
struct usb_interface {int dummy; } ;
struct sd {TYPE_1__* sensor; } ;
struct gspca_dev {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* disconnect ) (struct sd*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  D_PROBE ; 
 int /*<<< orphan*/  PDEBUG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gspca_disconnect (struct usb_interface*) ; 
 int /*<<< orphan*/  stub1 (struct sd*) ; 
 struct gspca_dev* usb_get_intfdata (struct usb_interface*) ; 

__attribute__((used)) static void sd_disconnect(struct usb_interface *intf)
{
	struct gspca_dev *gspca_dev = usb_get_intfdata(intf);
	struct sd *sd = (struct sd *) gspca_dev;
	PDEBUG(D_PROBE, "Disconnecting the stv06xx device");

	if (sd->sensor->disconnect)
		sd->sensor->disconnect(sd);
	gspca_disconnect(intf);
}