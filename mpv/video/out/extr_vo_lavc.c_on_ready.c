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
struct vo {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VO_EVENT_INITIAL_UNBLOCK ; 
 int /*<<< orphan*/  vo_event (struct vo*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void on_ready(void *ptr)
{
    struct vo *vo = ptr;

    vo_event(vo, VO_EVENT_INITIAL_UNBLOCK);
}