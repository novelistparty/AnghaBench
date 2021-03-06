#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct nvme_namespace {TYPE_2__* ctrlr; } ;
struct TYPE_3__ {scalar_t__ sn; } ;
struct TYPE_4__ {TYPE_1__ cdata; } ;

/* Variables and functions */

const char *
nvme_ns_get_serial_number(struct nvme_namespace *ns)
{
	return ((const char *)ns->ctrlr->cdata.sn);
}