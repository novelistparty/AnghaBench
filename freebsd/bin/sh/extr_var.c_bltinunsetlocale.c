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
struct TYPE_2__ {int count; int /*<<< orphan*/ * args; } ;

/* Variables and functions */
 int /*<<< orphan*/  INTOFF ; 
 int /*<<< orphan*/  INTON ; 
 int /*<<< orphan*/  LC_ALL ; 
 TYPE_1__* cmdenviron ; 
 scalar_t__ localevar (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setlocale (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  updatecharset () ; 

void
bltinunsetlocale(void)
{
	int i;

	INTOFF;
	if (cmdenviron) for (i = 0; i < cmdenviron->count; i++) {
		if (localevar(cmdenviron->args[i])) {
			setlocale(LC_ALL, "");
			updatecharset();
			break;
		}
	}
	INTON;
}