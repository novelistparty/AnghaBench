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
typedef  int u32 ;
struct TYPE_3__ {int iflag; int xflag; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_1__*) ; 
 TYPE_1__* f2fs_xflags_map ; 

__attribute__((used)) static inline u32 f2fs_iflags_to_xflags(u32 iflags)
{
	u32 xflags = 0;
	int i;

	for (i = 0; i < ARRAY_SIZE(f2fs_xflags_map); i++)
		if (iflags & f2fs_xflags_map[i].iflag)
			xflags |= f2fs_xflags_map[i].xflag;

	return xflags;
}