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
typedef  int u8 ;
struct adapter {TYPE_1__* HalData; } ;
struct TYPE_2__ {int UsbBulkOutSize; } ;

/* Variables and functions */
 int TXDESC_SIZE ; 

__attribute__((used)) static u8 urb_zero_packet_chk(struct adapter *adapt, int sz)
{
	return !((sz + TXDESC_SIZE) % adapt->HalData->UsbBulkOutSize);
}