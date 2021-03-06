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
struct mpv_global {int dummy; } ;

/* Variables and functions */
 char** mp_find_all_config_files_limited (void*,struct mpv_global*,int,char const*) ; 

char **mp_find_all_config_files(void *talloc_ctx, struct mpv_global *global,
                                const char *filename)
{
    return mp_find_all_config_files_limited(talloc_ctx, global, 64, filename);
}