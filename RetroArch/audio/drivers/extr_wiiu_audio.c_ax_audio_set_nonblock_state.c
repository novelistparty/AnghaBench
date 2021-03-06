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
struct TYPE_2__ {int nonblocking; } ;
typedef  TYPE_1__ ax_audio_t ;

/* Variables and functions */

__attribute__((used)) static void ax_audio_set_nonblock_state(void* data, bool state)
{
   ax_audio_t* ax = (ax_audio_t*)data;

   if (ax)
      ax->nonblocking = state;
}