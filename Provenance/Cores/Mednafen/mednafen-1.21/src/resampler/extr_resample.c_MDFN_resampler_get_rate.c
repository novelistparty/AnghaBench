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
typedef  int /*<<< orphan*/  spx_uint32_t ;
struct TYPE_3__ {int /*<<< orphan*/  out_rate; int /*<<< orphan*/  in_rate; } ;
typedef  TYPE_1__ SpeexResamplerState ;

/* Variables and functions */

void speex_resampler_get_rate(SpeexResamplerState *st, spx_uint32_t *in_rate, spx_uint32_t *out_rate)
{
   *in_rate = st->in_rate;
   *out_rate = st->out_rate;
}