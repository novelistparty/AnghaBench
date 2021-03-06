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
struct TYPE_2__ {unsigned int desc_count; unsigned int desc_avail; } ;
struct vnic_wq {TYPE_1__ ring; } ;

/* Variables and functions */

__attribute__((used)) static inline unsigned int svnic_wq_desc_used(struct vnic_wq *wq)
{
	/* how many does HW own? */
	return wq->ring.desc_count - wq->ring.desc_avail - 1;
}