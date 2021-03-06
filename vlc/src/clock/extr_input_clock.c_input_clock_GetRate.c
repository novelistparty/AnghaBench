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
struct TYPE_3__ {float rate; int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ input_clock_t ;

/* Variables and functions */
 int /*<<< orphan*/  vlc_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_mutex_unlock (int /*<<< orphan*/ *) ; 

float input_clock_GetRate( input_clock_t *cl )
{
    vlc_mutex_lock( &cl->lock );
    float rate = cl->rate;
    vlc_mutex_unlock( &cl->lock );

    return rate;
}