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
typedef  int s32 ;
struct TYPE_2__ {int connected; } ;

/* Variables and functions */
 int /*<<< orphan*/  USBKEYBOARD_DISCONNECTED ; 
 TYPE_1__* _kbd ; 
 int /*<<< orphan*/  _submit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static s32 _disconnect(s32 retval, void *data)
{
	(void) data;

	_kbd->connected = false;

	_submit(USBKEYBOARD_DISCONNECTED, 0);

	return 1;
}