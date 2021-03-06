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
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_3__ {int /*<<< orphan*/  slice_pic_parameter_set_id; } ;
typedef  TYPE_1__ hevc_slice_segment_header_t ;

/* Variables and functions */

uint8_t hevc_get_slice_pps_id( const hevc_slice_segment_header_t *p_slice )
{
    return p_slice->slice_pic_parameter_set_id;
}