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
typedef  int /*<<< orphan*/  movs ;
typedef  int /*<<< orphan*/  byte ;

/* Variables and functions */

__attribute__((used)) static void blit4_32( byte *src, byte *dst, int spl  )
{
	movs *dsrc, *ddst;
	int dspl;

	dsrc = (movs *)src;
	ddst = (movs *)dst;
	dspl = spl>>3;

	ddst[0] = dsrc[0]; ddst[1] = dsrc[1];
	dsrc += 2; ddst += dspl;
	ddst[0] = dsrc[0]; ddst[1] = dsrc[1];
	dsrc += 2; ddst += dspl;
	ddst[0] = dsrc[0]; ddst[1] = dsrc[1];
	dsrc += 2; ddst += dspl;
	ddst[0] = dsrc[0]; ddst[1] = dsrc[1];
}