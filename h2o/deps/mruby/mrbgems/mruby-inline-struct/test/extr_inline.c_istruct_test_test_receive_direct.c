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
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;

/* Variables and functions */
 int /*<<< orphan*/  mrb_bool_value (int) ; 
 int /*<<< orphan*/  mrb_get_args (int /*<<< orphan*/ *,char*,char**) ; 

__attribute__((used)) static mrb_value
istruct_test_test_receive_direct(mrb_state *mrb, mrb_value self)
{
  char *ptr;
  mrb_get_args(mrb, "I", &ptr);
  return mrb_bool_value(ptr[0] == 's');
}