#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct pcm_channel {int /*<<< orphan*/  bufsoft; } ;

/* Variables and functions */
 int /*<<< orphan*/  CHN_LOCKASSERT (struct pcm_channel*) ; 
 int /*<<< orphan*/  sndbuf_updateprevtotal (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
chn_pollreset(struct pcm_channel *c)
{

	CHN_LOCKASSERT(c);
	sndbuf_updateprevtotal(c->bufsoft);
}