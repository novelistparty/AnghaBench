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
 int /*<<< orphan*/  SetEvent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WINE_TRACE (char*) ; 
 int /*<<< orphan*/  kill_event ; 

__attribute__((used)) static void KillService(void)
{
    WINE_TRACE("Killing service\n");
    SetEvent(kill_event);
}