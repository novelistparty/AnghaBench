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
struct __gxfifo {scalar_t__ buf_start; } ;
typedef  int /*<<< orphan*/  GXFifoObj ;

/* Variables and functions */

void* GX_GetFifoBase(GXFifoObj *fifo)
{
	return (void*)((struct __gxfifo*)fifo)->buf_start;
}