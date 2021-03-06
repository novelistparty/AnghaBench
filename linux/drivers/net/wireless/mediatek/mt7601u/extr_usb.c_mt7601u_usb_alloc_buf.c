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
struct usb_device {int dummy; } ;
struct mt7601u_dma_buf {size_t len; int /*<<< orphan*/  buf; int /*<<< orphan*/  urb; int /*<<< orphan*/  dma; } ;
struct mt7601u_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 struct usb_device* mt7601u_to_usb_dev (struct mt7601u_dev*) ; 
 int /*<<< orphan*/  usb_alloc_coherent (struct usb_device*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  usb_alloc_urb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool mt7601u_usb_alloc_buf(struct mt7601u_dev *dev, size_t len,
			   struct mt7601u_dma_buf *buf)
{
	struct usb_device *usb_dev = mt7601u_to_usb_dev(dev);

	buf->len = len;
	buf->urb = usb_alloc_urb(0, GFP_KERNEL);
	buf->buf = usb_alloc_coherent(usb_dev, buf->len, GFP_KERNEL, &buf->dma);

	return !buf->urb || !buf->buf;
}