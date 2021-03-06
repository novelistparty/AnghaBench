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
struct TYPE_3__ {scalar_t__ ready_state; scalar_t__ doc_state; } ;
typedef  scalar_t__ READYSTATE ;
typedef  TYPE_1__ DocHost ;

/* Variables and functions */

void set_doc_state(DocHost *This, READYSTATE doc_state)
{
    This->doc_state = doc_state;
    if(doc_state > This->ready_state)
        This->ready_state = doc_state;
}