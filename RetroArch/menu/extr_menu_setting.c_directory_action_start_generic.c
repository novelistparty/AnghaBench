#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  string; } ;
struct TYPE_6__ {TYPE_1__ default_value; } ;
typedef  TYPE_2__ rarch_setting_t ;

/* Variables and functions */
 int /*<<< orphan*/  setting_set_with_string_representation (TYPE_2__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int directory_action_start_generic(rarch_setting_t *setting)
{
   if (!setting)
      return -1;

   setting_set_with_string_representation(setting,
         setting->default_value.string);

   return 0;
}