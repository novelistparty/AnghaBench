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
 int /*<<< orphan*/  os_free (void*) ; 

void espconn_memfree(void *fp, char* file, int line)
{
	//os_printf("%s %d %p\n",file, line, fp);
	os_free(fp);
	fp = NULL;
}