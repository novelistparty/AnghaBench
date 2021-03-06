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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  Ringbuffer_t ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,size_t) ; 
 int /*<<< orphan*/ * prvAcquireItemNoSplit (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  prvSendItemDoneNoSplit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void prvCopyItemNoSplit(Ringbuffer_t *pxRingbuffer, const uint8_t *pucItem, size_t xItemSize)
{
    uint8_t* item_addr = prvAcquireItemNoSplit(pxRingbuffer, xItemSize);
    memcpy(item_addr, pucItem, xItemSize);
    prvSendItemDoneNoSplit(pxRingbuffer, item_addr);
}