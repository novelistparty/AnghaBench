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
struct TYPE_3__ {int /*<<< orphan*/  ch_state; } ;
typedef  TYPE_1__ tGATT_TCB ;
typedef  int /*<<< orphan*/  tGATT_CH_STATE ;

/* Variables and functions */
 int /*<<< orphan*/  GATT_TRACE_DEBUG (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void gatt_set_ch_state(tGATT_TCB *p_tcb, tGATT_CH_STATE ch_state)
{
    if (p_tcb) {
        GATT_TRACE_DEBUG ("gatt_set_ch_state: old=%d new=%d", p_tcb->ch_state, ch_state);
        p_tcb->ch_state = ch_state;
    }
}