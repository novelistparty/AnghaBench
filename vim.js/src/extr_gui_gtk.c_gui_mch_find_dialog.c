#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_3__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  arg; } ;
typedef  TYPE_1__ exarg_T ;
struct TYPE_5__ {scalar_t__ in_use; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  find_replace_dialog_create (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_3__ gui ; 

void
gui_mch_find_dialog(exarg_T *eap)
{
    if (gui.in_use)
	find_replace_dialog_create(eap->arg, FALSE);
}