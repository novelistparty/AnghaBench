#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_4__ {struct TYPE_4__* pNext; } ;
struct TYPE_3__ {scalar_t__ numEnqueued; scalar_t__ numEnqueuedHW; int /*<<< orphan*/  numEnqueueOps; TYPE_2__* pTail; TYPE_2__* pHead; int /*<<< orphan*/ * pNext; } ;
typedef  int /*<<< orphan*/  DRV_SPI_SYS_QUEUE_RESULT ;
typedef  TYPE_1__ DRV_SPI_SYS_QUEUE_QUEUE_DATA ;
typedef  scalar_t__ DRV_SPI_SYS_QUEUE_HANDLE ;
typedef  TYPE_2__ DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_SPI_SYS_QUEUE_INVALID_PARAMETER ; 
 scalar_t__ DRV_SPI_SYS_QUEUE_MAX_ERROR ; 
 int /*<<< orphan*/  DRV_SPI_SYS_QUEUE_SUCCESS ; 

DRV_SPI_SYS_QUEUE_RESULT DRV_SPI_SYS_QUEUE_Enqueue(DRV_SPI_SYS_QUEUE_HANDLE queue, void * element)
{
    if ((queue <= 0) && (queue >= DRV_SPI_SYS_QUEUE_MAX_ERROR))
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_QUEUE_DATA * pQueue = (DRV_SPI_SYS_QUEUE_QUEUE_DATA *)queue;

    if (pQueue->pNext != NULL)
    {
        return DRV_SPI_SYS_QUEUE_INVALID_PARAMETER;
    }

    DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA * pEntry = (DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA *)((uint32_t)element - sizeof(DRV_SPI_SYS_QUEUE_FIFO_ELEMENT_DATA));

    if (pQueue->pHead == NULL)
    {
        pQueue->pHead = pEntry;
        pQueue->pTail = pEntry;
    }
    else
    {
        pQueue->pTail->pNext = pEntry;
        pQueue->pTail = pEntry;
    }

#if _SPI_DRV_SYS_QUEUE_TRACKING
    pQueue->numEnqueued++;
    if (pQueue->numEnqueued > pQueue->numEnqueuedHW)
    {
        pQueue->numEnqueuedHW = pQueue->numEnqueued;
    }
    pQueue->numEnqueueOps++;
#endif
    return DRV_SPI_SYS_QUEUE_SUCCESS;
}