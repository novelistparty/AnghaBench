#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct TYPE_5__* queue; } ;
typedef  TYPE_1__ Group_JitterBuffer ;

/* Variables and functions */
 int /*<<< orphan*/  clear_queue (TYPE_1__*) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 

__attribute__((used)) static void terminate_queue(Group_JitterBuffer *q)
{
    if (!q) return;

    clear_queue(q);
    free(q->queue);
    free(q);
}