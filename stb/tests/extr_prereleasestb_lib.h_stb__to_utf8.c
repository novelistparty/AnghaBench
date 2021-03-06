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
typedef  int /*<<< orphan*/  stb__wchar ;

/* Variables and functions */
 char* stb_to_utf8 (char*,int /*<<< orphan*/ *,int) ; 

char *stb__to_utf8(stb__wchar *str)
{
   static char buffer[4096];
   return stb_to_utf8(buffer, str, 4096);
}