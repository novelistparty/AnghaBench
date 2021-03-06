#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct intel_fbc {unsigned int possible_framebuffer_bits; TYPE_2__* crtc; scalar_t__ enabled; } ;
struct TYPE_6__ {unsigned int frontbuffer_bit; } ;
struct TYPE_4__ {int /*<<< orphan*/  primary; } ;
struct TYPE_5__ {TYPE_1__ base; } ;

/* Variables and functions */
 TYPE_3__* to_intel_plane (int /*<<< orphan*/ ) ; 

__attribute__((used)) static unsigned int intel_fbc_get_frontbuffer_bit(struct intel_fbc *fbc)
{
	if (fbc->enabled)
		return to_intel_plane(fbc->crtc->base.primary)->frontbuffer_bit;
	else
		return fbc->possible_framebuffer_bits;
}