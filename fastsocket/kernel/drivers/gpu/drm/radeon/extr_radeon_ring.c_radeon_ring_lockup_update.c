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
struct radeon_ring {int /*<<< orphan*/  last_activity; int /*<<< orphan*/  rptr; int /*<<< orphan*/  last_rptr; } ;

/* Variables and functions */
 int /*<<< orphan*/  jiffies ; 

void radeon_ring_lockup_update(struct radeon_ring *ring)
{
	ring->last_rptr = ring->rptr;
	ring->last_activity = jiffies;
}