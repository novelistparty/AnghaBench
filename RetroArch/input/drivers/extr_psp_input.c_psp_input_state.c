#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_6__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct retro_keybind {int /*<<< orphan*/  joyaxis; int /*<<< orphan*/  joykey; } ;
struct TYPE_9__ {float axis_threshold; int /*<<< orphan*/  joy_idx; TYPE_1__* auto_binds; } ;
typedef  TYPE_2__ rarch_joypad_info_t ;
struct TYPE_10__ {int /*<<< orphan*/ * keyboard_state; TYPE_6__* joypad; } ;
typedef  TYPE_3__ psp_input_t ;
typedef  int int16_t ;
typedef  enum retro_key { ____Placeholder_retro_key } retro_key ;
struct TYPE_11__ {int /*<<< orphan*/  (* axis ) (int /*<<< orphan*/ ,int /*<<< orphan*/  const) ;int /*<<< orphan*/  (* button ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
struct TYPE_8__ {int /*<<< orphan*/  joyaxis; int /*<<< orphan*/  joykey; } ;

/* Variables and functions */
 int /*<<< orphan*/  AXIS_NONE ; 
 int /*<<< orphan*/  NO_BTN ; 
#define  RARCH_DEVICE_MOUSE_SCREEN 132 
 unsigned int RARCH_FIRST_CUSTOM_BIND ; 
 unsigned int RETROK_LAST ; 
#define  RETRO_DEVICE_ANALOG 131 
 unsigned int RETRO_DEVICE_ID_JOYPAD_MASK ; 
#define  RETRO_DEVICE_JOYPAD 130 
#define  RETRO_DEVICE_KEYBOARD 129 
#define  RETRO_DEVICE_MOUSE 128 
 scalar_t__ abs (int /*<<< orphan*/ ) ; 
 int input_joypad_analog (TYPE_6__*,TYPE_2__,unsigned int,unsigned int,unsigned int,struct retro_keybind const*) ; 
 int psp_input_mouse_state (TYPE_3__*,unsigned int,int) ; 
 size_t* rarch_keysym_lut ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ,int /*<<< orphan*/  const) ; 

__attribute__((used)) static int16_t psp_input_state(void *data,
      rarch_joypad_info_t joypad_info,
      const struct retro_keybind **binds,
      unsigned port, unsigned device,
      unsigned idx, unsigned id)
{
   psp_input_t *psp           = (psp_input_t*)data;

#if !defined(SN_TARGET_PSP2) && !defined(VITA)
   if (port > 0)
      return 0;
#endif

   switch (device)
   {
      case RETRO_DEVICE_JOYPAD:
         if (id == RETRO_DEVICE_ID_JOYPAD_MASK)
         {
            unsigned i;
            int16_t ret = 0;
            for (i = 0; i < RARCH_FIRST_CUSTOM_BIND; i++)
            {
               /* Auto-binds are per joypad, not per user. */
               const uint64_t joykey  = (binds[port][i].joykey != NO_BTN)
                  ? binds[port][i].joykey : joypad_info.auto_binds[i].joykey;
               const uint32_t joyaxis = (binds[port][i].joyaxis != AXIS_NONE)
                  ? binds[port][i].joyaxis : joypad_info.auto_binds[i].joyaxis;

               if ((uint16_t)joykey != NO_BTN && psp->joypad->button(joypad_info.joy_idx, (uint16_t)joykey))
               {
                  ret |= (1 << i);
                  continue;
               }
               if (((float)abs(psp->joypad->axis(joypad_info.joy_idx, joyaxis)) / 0x8000) > joypad_info.axis_threshold)
               {
                  ret |= (1 << i);
                  continue;
               }
            }

            return ret;
         }
         else
         {
            /* Auto-binds are per joypad, not per user. */
            const uint64_t joykey  = (binds[port][id].joykey != NO_BTN)
               ? binds[port][id].joykey : joypad_info.auto_binds[id].joykey;
            const uint32_t joyaxis = (binds[port][id].joyaxis != AXIS_NONE)
               ? binds[port][id].joyaxis : joypad_info.auto_binds[id].joyaxis;

            if ((uint16_t)joykey != NO_BTN && psp->joypad->button(joypad_info.joy_idx, (uint16_t)joykey))
               return true;
            if (((float)abs(psp->joypad->axis(joypad_info.joy_idx, joyaxis)) / 0x8000) > joypad_info.axis_threshold)
               return true;
         }
         break;
      case RETRO_DEVICE_ANALOG:
         if (binds[port])
            return input_joypad_analog(psp->joypad, joypad_info, port, idx, id, binds[port]);
         break;
#ifdef VITA
      case RETRO_DEVICE_KEYBOARD:
         return ((id < RETROK_LAST) && psp->keyboard_state[rarch_keysym_lut[(enum retro_key)id]]);
         break;
      case RETRO_DEVICE_MOUSE:
         return psp_input_mouse_state(psp, id, false);
         break;
      case RARCH_DEVICE_MOUSE_SCREEN:
         return psp_input_mouse_state(psp, id, true);
         break;
#endif
   }

   return 0;
}