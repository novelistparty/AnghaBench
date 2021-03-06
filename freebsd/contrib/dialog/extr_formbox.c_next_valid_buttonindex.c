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

/* Variables and functions */
 int dlg_next_ok_buttonindex (int,int) ; 
 int sTEXT ; 

__attribute__((used)) static int
next_valid_buttonindex(int state, int extra, bool non_editable)
{
    state = dlg_next_ok_buttonindex(state, extra);
    while (non_editable && state == sTEXT)
	state = dlg_next_ok_buttonindex(state, sTEXT);
    return state;
}