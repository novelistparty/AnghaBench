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
#define  KBINFO 128 
 int /*<<< orphan*/  SEND_STRING (char*) ; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KBINFO:
      if (record->event.pressed) {
        SEND_STRING("Hello from Illuminati Works");
      } else {
		SEND_STRING("iS0 working properly");
      }
      break;
  }
  return true;
}