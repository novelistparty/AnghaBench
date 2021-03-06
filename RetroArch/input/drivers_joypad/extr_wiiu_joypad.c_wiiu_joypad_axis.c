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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* axis ) (unsigned int,int /*<<< orphan*/ ) ;} ;

/* Variables and functions */
 TYPE_1__** pad_drivers ; 
 int /*<<< orphan*/  stub1 (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wiiu_joypad_query_pad (unsigned int) ; 

__attribute__((used)) static int16_t wiiu_joypad_axis(unsigned pad, uint32_t joyaxis)
{
   if (!wiiu_joypad_query_pad(pad))
      return 0;

   return pad_drivers[pad]->axis(pad, joyaxis);
}