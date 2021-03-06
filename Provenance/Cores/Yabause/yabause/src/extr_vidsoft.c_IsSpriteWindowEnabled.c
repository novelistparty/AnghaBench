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
typedef  int u16 ;

/* Variables and functions */

int IsSpriteWindowEnabled(u16 wtcl)
{
   if (((wtcl& (1 << 13)) == 0) &&
      ((wtcl & (1 << 5)) == 0))
      return 0;

   return 1;
}