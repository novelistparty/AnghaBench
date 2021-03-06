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
struct vpo_nibble {int l; int h; } ;

/* Variables and functions */

__attribute__((used)) static int
nibble_inbyte_hook (void *p, char *ptr)
{
	struct vpo_nibble *s = (struct vpo_nibble *)p;

	/* increment the buffer pointer */
	*ptr++ = ((s->l >> 4) & 0x0f) + (s->h & 0xf0);

	return (0);
}