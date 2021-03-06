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
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_2__ {int /*<<< orphan*/  slice_group_id_ref; } ;
typedef  TYPE_1__ H264RawPPS ;

/* Variables and functions */
 int /*<<< orphan*/  av_buffer_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  av_freep (int /*<<< orphan*/ **) ; 

__attribute__((used)) static void cbs_h264_free_pps(void *opaque, uint8_t *content)
{
    H264RawPPS *pps = (H264RawPPS*)content;
    av_buffer_unref(&pps->slice_group_id_ref);
    av_freep(&content);
}