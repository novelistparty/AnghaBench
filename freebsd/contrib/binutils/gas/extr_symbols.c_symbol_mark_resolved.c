#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int sy_resolved; } ;
typedef  TYPE_1__ symbolS ;
struct local_symbol {int dummy; } ;

/* Variables and functions */
 scalar_t__ LOCAL_SYMBOL_CHECK (TYPE_1__*) ; 
 int /*<<< orphan*/  local_symbol_mark_resolved (struct local_symbol*) ; 

void
symbol_mark_resolved (symbolS *s)
{
  if (LOCAL_SYMBOL_CHECK (s))
    {
      local_symbol_mark_resolved ((struct local_symbol *) s);
      return;
    }
  s->sy_resolved = 1;
}