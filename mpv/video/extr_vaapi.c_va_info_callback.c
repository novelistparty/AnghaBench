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
 int /*<<< orphan*/  MSGL_V ; 
 int /*<<< orphan*/  va_message_callback (void*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void va_info_callback(void *context, const char *msg)
{
    va_message_callback(context, msg, MSGL_V);
}