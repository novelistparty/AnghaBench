#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint16_t ;
struct TYPE_4__ {int /*<<< orphan*/  pressed; } ;
struct TYPE_5__ {TYPE_1__ event; } ;
typedef  TYPE_2__ keyrecord_t ;

/* Variables and functions */
 int /*<<< orphan*/  PLAY_NOTE_ARRAY (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
#define  QWERTY 128 
 unsigned long _QWERTY ; 
 int /*<<< orphan*/  persistant_default_layer_set (unsigned long) ; 
 int /*<<< orphan*/  tone_qwerty ; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistant_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    //case COLEMAK:
      //if (record->event.pressed) {
        //#ifdef AUDIO_ENABLE
          //PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        //#endif
        //persistant_default_layer_set(1UL<<_COLEMAK);
      //}
      //return false;
      //break;
  }
  return true;
}