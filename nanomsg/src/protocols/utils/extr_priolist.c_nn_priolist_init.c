#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct nn_priolist {int current; TYPE_1__* slots; } ;
struct TYPE_2__ {int /*<<< orphan*/ * current; int /*<<< orphan*/  pipes; } ;

/* Variables and functions */
 int NN_PRIOLIST_SLOTS ; 
 int /*<<< orphan*/  nn_list_init (int /*<<< orphan*/ *) ; 

void nn_priolist_init (struct nn_priolist *self)
{
    int i;

    for (i = 0; i != NN_PRIOLIST_SLOTS; ++i) {
        nn_list_init (&self->slots [i].pipes);
        self->slots [i].current = NULL;
    }
    self->current = -1;
}