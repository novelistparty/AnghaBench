#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ help; int /*<<< orphan*/  items; } ;
typedef  TYPE_1__ rc_menu ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,unsigned int) ; 
 int /*<<< orphan*/  write_rc_menuitems (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
write_rc_menu (FILE *e, const rc_menu *menu, int menuex)
{
  if (menu->help != 0)
    fprintf (e, "// Help ID: %u\n", (unsigned int) menu->help);
  write_rc_menuitems (e, menu->items, menuex, 0);
}