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
typedef  scalar_t__ uint32_t ;
typedef  int int16_t ;

/* Variables and functions */
 int AXIS_NEG_GET (scalar_t__) ; 
 scalar_t__ AXIS_NONE ; 
 int AXIS_POS_GET (scalar_t__) ; 
 unsigned int DEFAULT_MAX_PADS ; 
 int*** analog_state ; 

__attribute__((used)) static int16_t switch_joypad_axis(unsigned port_num, uint32_t joyaxis)
{
   int val     = 0;
   int axis    = -1;
   bool is_neg = false;
   bool is_pos = false;

#if 0
   /* TODO/FIXME - implement */
   if (joyaxis == AXIS_NONE || port_num >= DEFAULT_MAX_PADS) { }
#endif

   if (AXIS_NEG_GET(joyaxis) < 4)
   {
      axis = AXIS_NEG_GET(joyaxis);
      is_neg = true;
   }
   else if (AXIS_POS_GET(joyaxis) < 4)
   {
      axis = AXIS_POS_GET(joyaxis);
      is_pos = true;
   }

   switch(axis)
   {
      case 0:
         val = analog_state[port_num][0][0];
         break;
      case 1:
         val = analog_state[port_num][0][1];
         break;
      case 2:
         val = analog_state[port_num][1][0];
         break;
      case 3:
         val = analog_state[port_num][1][1];
         break;
   }

   if (is_neg && val > 0)
      val = 0;
   else if (is_pos && val < 0)
      val = 0;

   return val;
}