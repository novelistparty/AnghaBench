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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  ocs_domain_t ;

/* Variables and functions */
 int /*<<< orphan*/  __ocs_domain_attach_internal (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void
ocs_domain_attach(ocs_domain_t *domain, uint32_t s_id)
{
	__ocs_domain_attach_internal(domain, s_id);
}