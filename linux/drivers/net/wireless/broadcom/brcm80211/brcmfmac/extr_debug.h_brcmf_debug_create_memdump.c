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
struct brcmf_bus {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline
int brcmf_debug_create_memdump(struct brcmf_bus *bus, const void *data,
			       size_t len)
{
	return 0;
}