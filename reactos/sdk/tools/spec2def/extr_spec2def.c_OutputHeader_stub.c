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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ gbTracing ; 

void
OutputHeader_stub(FILE *file)
{
    fprintf(file, "/* This file is autogenerated, do not edit. */\n\n"
            "#include <stubs.h>\n");

    if (gbTracing)
    {
        fprintf(file, "#include <wine/debug.h>\n");
        fprintf(file, "#include <inttypes.h>\n");
        fprintf(file, "WINE_DECLARE_DEBUG_CHANNEL(relay);\n");
    }

    fprintf(file, "\n");
}