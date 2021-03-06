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
struct TYPE_2__ {int ts; } ;
typedef  TYPE_1__ Syncpoint ;

/* Variables and functions */

int ff_nut_sp_pts_cmp(const void *a, const void *b)
{
    const Syncpoint *va = a, *vb = b;
    return ((va->ts - vb->ts) >> 32) - ((vb->ts - va->ts) >> 32);
}