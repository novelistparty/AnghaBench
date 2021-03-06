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
typedef  int /*<<< orphan*/  ecma_value_t ;
typedef  int /*<<< orphan*/  ecma_number_t ;

/* Variables and functions */
 int /*<<< orphan*/  ecma_make_boolean_value (int) ; 
 scalar_t__ ecma_number_is_infinity (int /*<<< orphan*/ ) ; 
 scalar_t__ ecma_number_is_nan (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ecma_value_t
ecma_builtin_global_object_is_finite (ecma_number_t arg_num) /**< routine's first argument */
{
  bool is_finite = !(ecma_number_is_nan (arg_num)
                     || ecma_number_is_infinity (arg_num));

  return ecma_make_boolean_value (is_finite);
}