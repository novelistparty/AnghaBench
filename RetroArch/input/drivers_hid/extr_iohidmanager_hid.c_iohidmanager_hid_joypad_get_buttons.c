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
struct TYPE_2__ {int /*<<< orphan*/ * slots; } ;
typedef  TYPE_1__ iohidmanager_hid_t ;
typedef  int /*<<< orphan*/  input_bits_t ;

/* Variables and functions */
 int /*<<< orphan*/  BIT256_CLEAR_ALL_PTR (int /*<<< orphan*/ *) ; 
 void pad_connection_get_buttons (int /*<<< orphan*/ *,unsigned int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void iohidmanager_hid_joypad_get_buttons(void *data,
      unsigned port, input_bits_t *state)
{
  iohidmanager_hid_t        *hid   = (iohidmanager_hid_t*)data;
  if (hid)
    return pad_connection_get_buttons(&hid->slots[port], port, state);
  else
    BIT256_CLEAR_ALL_PTR(state);
}