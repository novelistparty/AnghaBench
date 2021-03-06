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
typedef  int /*<<< orphan*/  mpv_handle ;
typedef  int /*<<< orphan*/  js_State ;

/* Variables and functions */
 int /*<<< orphan*/  MPV_FORMAT_FLAG ; 
 int /*<<< orphan*/ * jclient (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  js_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  js_tostring (int /*<<< orphan*/ *,int) ; 
 int mpv_get_property (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  pushed_error (int /*<<< orphan*/ *,int,int) ; 

__attribute__((used)) static void script_get_property_bool(js_State *J)
{
    int result;
    mpv_handle *h = jclient(J);
    int e = mpv_get_property(h, js_tostring(J, 1), MPV_FORMAT_FLAG, &result);
    if (!pushed_error(J, e, 2))
        js_pushboolean(J, result);
}