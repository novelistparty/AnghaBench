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

/* Variables and functions */
 int /*<<< orphan*/  git_default_date ; 
 int /*<<< orphan*/  strbuf_reset (int /*<<< orphan*/ *) ; 

void reset_ident_date(void)
{
	strbuf_reset(&git_default_date);
}