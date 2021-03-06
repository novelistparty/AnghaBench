#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ uxMessagesWaiting; scalar_t__ uxLength; } ;
typedef  TYPE_1__ Queue_t ;
typedef  int /*<<< orphan*/  BaseType_t ;

/* Variables and functions */
 int /*<<< orphan*/  pdFALSE ; 
 int /*<<< orphan*/  pdTRUE ; 
 int /*<<< orphan*/  taskENTER_CRITICAL () ; 
 int /*<<< orphan*/  taskEXIT_CRITICAL () ; 

__attribute__((used)) static BaseType_t prvIsQueueFull( const Queue_t *pxQueue )
{
BaseType_t xReturn;

	taskENTER_CRITICAL();
	{
		if( pxQueue->uxMessagesWaiting == pxQueue->uxLength )
		{
			xReturn = pdTRUE;
		}
		else
		{
			xReturn = pdFALSE;
		}
	}
	taskEXIT_CRITICAL();

	return xReturn;
}