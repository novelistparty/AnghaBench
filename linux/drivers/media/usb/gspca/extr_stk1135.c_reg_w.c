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
typedef  int /*<<< orphan*/  u16 ;
struct usb_device {int dummy; } ;
struct gspca_dev {int usb_err; struct usb_device* dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  D_USBO ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_DEVICE ; 
 int USB_TYPE_VENDOR ; 
 int /*<<< orphan*/  gspca_dbg (struct gspca_dev*,int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int) ; 
 int usb_control_msg (struct usb_device*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  usb_sndctrlpipe (struct usb_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void reg_w(struct gspca_dev *gspca_dev, u16 index, u8 val)
{
	int ret;
	struct usb_device *dev = gspca_dev->dev;

	if (gspca_dev->usb_err < 0)
		return;
	ret = usb_control_msg(dev, usb_sndctrlpipe(dev, 0),
			0x01,
			USB_DIR_OUT | USB_TYPE_VENDOR | USB_RECIP_DEVICE,
			val,
			index,
			NULL,
			0,
			500);
	gspca_dbg(gspca_dev, D_USBO, "reg_w 0x%x:=0x%02x\n", index, val);
	if (ret < 0) {
		pr_err("reg_w 0x%x err %d\n", index, ret);
		gspca_dev->usb_err = ret;
	}
}