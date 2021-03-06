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
struct hidpad_ps3_data {int /*<<< orphan*/  buttons; } ;
typedef  int /*<<< orphan*/  input_bits_t ;

/* Variables and functions */
 int /*<<< orphan*/  BIT256_CLEAR_ALL_PTR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BITS_COPY32_PTR (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void hidpad_ps3_get_buttons(void *data, input_bits_t *state)
{
	struct hidpad_ps3_data *device = (struct hidpad_ps3_data*)data;
	if ( device )
	{
		/* copy 32 bits : needed for PS button? */
		BITS_COPY32_PTR(state, device->buttons);
	}
	else
      BIT256_CLEAR_ALL_PTR(state);
}