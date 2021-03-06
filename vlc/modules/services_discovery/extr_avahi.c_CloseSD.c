#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_5__ {TYPE_2__* p_sys; } ;
typedef  TYPE_1__ services_discovery_t ;
struct TYPE_6__ {int /*<<< orphan*/  services_name_to_input_item; } ;
typedef  TYPE_2__ discovery_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  CloseCommon (TYPE_2__*) ; 
 int /*<<< orphan*/  clear_input_item ; 
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  vlc_dictionary_clear (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void CloseSD( vlc_object_t *p_this )
{
    services_discovery_t *p_sd = ( services_discovery_t* )p_this;
    discovery_sys_t *p_sys = p_sd->p_sys;
    CloseCommon( p_sys );
    vlc_dictionary_clear( &p_sys->services_name_to_input_item,
                          clear_input_item, NULL );
    free( p_sys );
}