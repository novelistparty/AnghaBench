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
struct usbhs_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  usbhs_mod_gadget_remove (struct usbhs_priv*) ; 
 int /*<<< orphan*/  usbhs_mod_host_remove (struct usbhs_priv*) ; 

void usbhs_mod_remove(struct usbhs_priv *priv)
{
	usbhs_mod_host_remove(priv);
	usbhs_mod_gadget_remove(priv);
}