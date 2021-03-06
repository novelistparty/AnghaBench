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
typedef  int /*<<< orphan*/  h2o_mruby_error_stream_t ;

/* Variables and functions */
 int /*<<< orphan*/  error_stream_type ; 
 int /*<<< orphan*/ * mrb_data_check_get_ptr (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

h2o_mruby_error_stream_t *h2o_mruby_get_error_stream(mrb_state *mrb, mrb_value obj)
{
    h2o_mruby_error_stream_t *error_stream = mrb_data_check_get_ptr(mrb, obj, &error_stream_type);
    return error_stream;
}