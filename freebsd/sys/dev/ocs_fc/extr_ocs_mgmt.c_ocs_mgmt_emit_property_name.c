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
typedef  int /*<<< orphan*/  ocs_textbuf_t ;

/* Variables and functions */
 int /*<<< orphan*/  mode_string (int) ; 
 int /*<<< orphan*/  ocs_textbuf_printf (int /*<<< orphan*/ *,char*,char const*,int /*<<< orphan*/ ) ; 

void ocs_mgmt_emit_property_name(ocs_textbuf_t *textbuf, int mode, const char *name)
{
	ocs_textbuf_printf(textbuf, "<%s mode=\"%s\"/>\n", name, mode_string(mode));
}