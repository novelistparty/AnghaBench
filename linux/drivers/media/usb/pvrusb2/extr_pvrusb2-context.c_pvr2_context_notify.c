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
struct pvr2_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  pvr2_context_set_notify (struct pvr2_context*,int) ; 

__attribute__((used)) static void pvr2_context_notify(struct pvr2_context *mp)
{
	pvr2_context_set_notify(mp,!0);
}