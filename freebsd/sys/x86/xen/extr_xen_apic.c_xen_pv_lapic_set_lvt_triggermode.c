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
typedef  int /*<<< orphan*/  u_int ;
typedef  enum intr_trigger { ____Placeholder_intr_trigger } intr_trigger ;

/* Variables and functions */
 int /*<<< orphan*/  XEN_APIC_UNSUPPORTED ; 

__attribute__((used)) static int
xen_pv_lapic_set_lvt_triggermode(u_int apic_id, u_int lvt,
    enum intr_trigger trigger)
{

	XEN_APIC_UNSUPPORTED;
	return (0);
}