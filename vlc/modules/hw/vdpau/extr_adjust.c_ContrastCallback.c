#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  f_float; } ;
typedef  TYPE_1__ vlc_value_t ;
typedef  int /*<<< orphan*/  vlc_object_t ;

/* Variables and functions */
 int VLC_SUCCESS ; 
 int /*<<< orphan*/  vlc_atomic_store_float (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlc_to_vdp_contrast (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ContrastCallback(vlc_object_t *obj, const char *varname,
                            vlc_value_t prev, vlc_value_t cur, void *data)
{
    vlc_atomic_store_float(data, vlc_to_vdp_contrast(cur.f_float));
    (void) obj; (void) varname; (void) prev;
    return VLC_SUCCESS;
}