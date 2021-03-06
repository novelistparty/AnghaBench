#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  (* finalize ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_4__ {int /*<<< orphan*/  p_allocator; } ;
typedef  TYPE_1__ GstVlcVideoPool ;
typedef  int /*<<< orphan*/  GObject ;

/* Variables and functions */
 TYPE_1__* GST_VLC_VIDEO_POOL_CAST (int /*<<< orphan*/ *) ; 
 TYPE_2__* G_OBJECT_CLASS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gst_object_unref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  parent_class ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void gst_vlc_video_pool_finalize( GObject *p_object )
{
    GstVlcVideoPool *p_pool = GST_VLC_VIDEO_POOL_CAST( p_object );

    gst_object_unref( p_pool->p_allocator );

    G_OBJECT_CLASS( parent_class )->finalize( p_object );
}