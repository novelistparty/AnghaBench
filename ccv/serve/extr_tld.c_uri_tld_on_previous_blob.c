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
struct TYPE_2__ {int /*<<< orphan*/  previous; } ;
typedef  TYPE_1__ tld_param_parser_t ;
typedef  int /*<<< orphan*/  ebb_buf ;

/* Variables and functions */

__attribute__((used)) static void uri_tld_on_previous_blob(void* context, ebb_buf data)
{
	tld_param_parser_t* parser = (tld_param_parser_t*)context;
	parser->previous = data;
}