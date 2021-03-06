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
struct reg {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  fatal (char*,char const*) ; 
 int num_registers ; 
 struct reg* reg_defs ; 
 int /*<<< orphan*/  strcmp (char const*,int /*<<< orphan*/ ) ; 

struct reg *
find_register_by_name (const char *name)
{
  int i;

  for (i = 0; i < num_registers; i++)
    if (!strcmp (name, reg_defs[i].name))
      return &reg_defs[i];
  fatal ("Unknown register %s requested", name);
  return 0;
}