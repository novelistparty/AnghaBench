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
struct usbhs_pipe {int dummy; } ;

/* Variables and functions */
 int BSTS ; 
 int EBUSY ; 
 int usbhsp_pipectrl_get (struct usbhs_pipe*) ; 

int usbhs_pipe_is_accessible(struct usbhs_pipe *pipe)
{
	u16 val;

	val = usbhsp_pipectrl_get(pipe);
	if (val & BSTS)
		return 0;

	return -EBUSY;
}