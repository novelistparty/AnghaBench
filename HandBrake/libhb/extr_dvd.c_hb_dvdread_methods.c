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
typedef  int /*<<< orphan*/  hb_dvd_func_t ;

/* Variables and functions */
 int /*<<< orphan*/  hb_dvdread_func ; 

hb_dvd_func_t * hb_dvdread_methods( void )
{
    return &hb_dvdread_func;
}