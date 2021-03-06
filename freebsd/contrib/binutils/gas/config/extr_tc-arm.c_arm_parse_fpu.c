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
struct arm_option_cpu_value_table {int /*<<< orphan*/  value; int /*<<< orphan*/ * name; } ;

/* Variables and functions */
 int /*<<< orphan*/  _ (char*) ; 
 struct arm_option_cpu_value_table* arm_fpus ; 
 int /*<<< orphan*/  as_bad (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * mfpu_opt ; 
 scalar_t__ streq (int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static int
arm_parse_fpu (char * str)
{
  const struct arm_option_cpu_value_table * opt;

  for (opt = arm_fpus; opt->name != NULL; opt++)
    if (streq (opt->name, str))
      {
	mfpu_opt = &opt->value;
	return 1;
      }

  as_bad (_("unknown floating point format `%s'\n"), str);
  return 0;
}