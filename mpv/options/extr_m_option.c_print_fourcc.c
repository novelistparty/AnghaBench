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
typedef  int /*<<< orphan*/  m_option_t ;

/* Variables and functions */
 char* talloc_asprintf (int /*<<< orphan*/ *,char*,unsigned int) ; 

__attribute__((used)) static char *print_fourcc(const m_option_t *opt, const void *val)
{
    unsigned int fourcc = *(unsigned int *)val;
    return talloc_asprintf(NULL, "%08x", fourcc);
}