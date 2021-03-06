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
struct clar_summary {int /*<<< orphan*/  fp; } ;

/* Variables and functions */
 int fprintf (int /*<<< orphan*/ ,char*,char const*,char const*,char const*) ; 

int clar_summary_failure(struct clar_summary *summary,
    const char *type, const char *message, const char *desc)
{
	return fprintf(summary->fp,
	    "\t\t\t<failure type=\"%s\"><![CDATA[%s\n%s]]></failure>\n",
	    type, message, desc);
}