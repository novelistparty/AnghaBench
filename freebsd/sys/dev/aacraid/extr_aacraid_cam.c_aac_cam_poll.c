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
struct cam_sim {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static void
aac_cam_poll(struct cam_sim *sim)
{
	/*
	 * Pinging the interrupt routine isn't very safe, nor is it
	 * really necessary.  Do nothing.
	 */
}