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
struct TYPE_4__ {TYPE_2__* sys; } ;
typedef  TYPE_1__ audio_output_t ;
struct TYPE_5__ {int mute; int /*<<< orphan*/  volume; int /*<<< orphan*/  hdl; } ;
typedef  TYPE_2__ aout_sys_t ;

/* Variables and functions */
 int /*<<< orphan*/  sio_setvol (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int MuteSet (audio_output_t *aout, bool mute)
{
    aout_sys_t *sys = aout->sys;

    if (!sio_setvol (sys->hdl, mute ? 0 : sys->volume))
        return -1;

    sys->mute = mute;
    return 0;
}