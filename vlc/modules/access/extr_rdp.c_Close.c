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
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_3__ {int /*<<< orphan*/  out; TYPE_2__* p_sys; } ;
typedef  TYPE_1__ demux_t ;
struct TYPE_4__ {int /*<<< orphan*/  psz_hostname; scalar_t__ p_block; int /*<<< orphan*/  p_instance; scalar_t__ es; int /*<<< orphan*/  thread; } ;
typedef  TYPE_2__ demux_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  block_Release (scalar_t__) ; 
 int /*<<< orphan*/  es_out_Del (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  freerdp_channels_global_uninit () ; 
 int /*<<< orphan*/  freerdp_disconnect (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  freerdp_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_cancel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void Close( vlc_object_t *p_this )
{
    demux_t     *p_demux = (demux_t*)p_this;
    demux_sys_t *p_sys = p_demux->p_sys;

    vlc_cancel( p_sys->thread );
    vlc_join( p_sys->thread, NULL );

    if ( p_sys->es )
        es_out_Del( p_demux->out, p_sys->es );

    freerdp_disconnect( p_sys->p_instance );
    freerdp_free( p_sys->p_instance );
#if FREERDP_VERSION_MAJOR == 1 && FREERDP_VERSION_MINOR < 2
    freerdp_channels_global_uninit();
#endif

    if ( p_sys->p_block )
        block_Release( p_sys->p_block );

    free( p_sys->psz_hostname );
}