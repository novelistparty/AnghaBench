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
typedef  int /*<<< orphan*/  webvtt_cue_settings_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (char*) ; 
 char* strchr (char*,char) ; 
 char* strndup (char*,int) ; 
 char* strtok_r (char*,char*,char**) ; 
 int /*<<< orphan*/  webvtt_cue_settings_ParseTuple (int /*<<< orphan*/ *,char*,char const*) ; 

__attribute__((used)) static void webvtt_cue_settings_Parse( webvtt_cue_settings_t *p_settings,
                                       char *p_str )
{
    char *p_save;
    char *psz_tuple;
    do
    {
        psz_tuple = strtok_r( p_str, " ", &p_save );
        p_str = NULL;
        if( psz_tuple )
        {
            const char *psz_split = strchr( psz_tuple, ':' );
            if( psz_split && psz_split[1] != 0 && psz_split != psz_tuple )
            {
                char *psz_key = strndup( psz_tuple, psz_split - psz_tuple );
                if( psz_key )
                {
                    webvtt_cue_settings_ParseTuple( p_settings, psz_key, psz_split + 1 );
                    free( psz_key );
                }
            }
        }
    } while( psz_tuple );
}