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
 int debug_on ; 
 char* getenv (char*) ; 
 scalar_t__ strstr (char*,char*) ; 

__attribute__((used)) static int init_debug()
{
    char* str=getenv("CXTEST_DEBUG");
    if (str && strstr(str, "+hook"))
        debug_on=1;
    return debug_on;
}