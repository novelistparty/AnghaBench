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
typedef  int /*<<< orphan*/  gs_zstencil_t ;
struct TYPE_3__ {int /*<<< orphan*/ * cur_zstencil_buffer; } ;
typedef  TYPE_1__ gs_device_t ;

/* Variables and functions */

gs_zstencil_t *device_get_zstencil_target(const gs_device_t *device)
{
	return device->cur_zstencil_buffer;
}