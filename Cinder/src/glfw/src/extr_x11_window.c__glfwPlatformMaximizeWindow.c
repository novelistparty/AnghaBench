#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  _GLFWwindow ;
struct TYPE_3__ {int /*<<< orphan*/  display; scalar_t__ NET_WM_STATE_MAXIMIZED_HORZ; scalar_t__ NET_WM_STATE_MAXIMIZED_VERT; scalar_t__ NET_WM_STATE; } ;
struct TYPE_4__ {TYPE_1__ x11; } ;

/* Variables and functions */
 int /*<<< orphan*/  XFlush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _NET_WM_STATE_ADD ; 
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  sendEventToWM (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ,scalar_t__,scalar_t__,int,int /*<<< orphan*/ ) ; 

void _glfwPlatformMaximizeWindow(_GLFWwindow* window)
{
    if (_glfw.x11.NET_WM_STATE &&
        _glfw.x11.NET_WM_STATE_MAXIMIZED_VERT &&
        _glfw.x11.NET_WM_STATE_MAXIMIZED_HORZ)
    {
        sendEventToWM(window,
                      _glfw.x11.NET_WM_STATE,
                      _NET_WM_STATE_ADD,
                      _glfw.x11.NET_WM_STATE_MAXIMIZED_VERT,
                      _glfw.x11.NET_WM_STATE_MAXIMIZED_HORZ,
                      1, 0);
        XFlush(_glfw.x11.display);
    }
}