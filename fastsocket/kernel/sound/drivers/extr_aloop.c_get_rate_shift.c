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
struct loopback_pcm {int dummy; } ;
struct TYPE_2__ {unsigned int rate_shift; } ;

/* Variables and functions */
 TYPE_1__* get_setup (struct loopback_pcm*) ; 

__attribute__((used)) static inline unsigned int get_rate_shift(struct loopback_pcm *dpcm)
{
	return get_setup(dpcm)->rate_shift;
}