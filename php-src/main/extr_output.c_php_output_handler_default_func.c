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
typedef  int /*<<< orphan*/  php_output_context ;

/* Variables and functions */
 int SUCCESS ; 
 int /*<<< orphan*/  php_output_context_pass (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int php_output_handler_default_func(void **handler_context, php_output_context *output_context)
{
	php_output_context_pass(output_context);
	return SUCCESS;
}