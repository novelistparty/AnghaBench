#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  encoder_options; } ;
typedef  TYPE_1__ hb_job_t ;

/* Variables and functions */
 int /*<<< orphan*/  hb_update_str (int /*<<< orphan*/ *,char const*) ; 

void hb_job_set_encoder_options(hb_job_t *job, const char *options)
{
    if (job != NULL)
    {
        if (options == NULL || options[0] == 0)
        {
            options = NULL;
        }
        hb_update_str(&job->encoder_options, options);
    }
}