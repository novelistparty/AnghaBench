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
struct TYPE_3__ {int /*<<< orphan*/  system_sleep_opaque; } ;
typedef  TYPE_1__ hb_handle_t ;

/* Variables and functions */
 int /*<<< orphan*/  hb_system_sleep_private_disable (int /*<<< orphan*/ ) ; 

void hb_system_sleep_prevent(hb_handle_t *h)
{
    hb_system_sleep_private_disable(h->system_sleep_opaque);
}