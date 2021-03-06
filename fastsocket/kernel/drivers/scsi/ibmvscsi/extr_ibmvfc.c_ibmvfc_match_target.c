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
struct ibmvfc_event {TYPE_1__* cmnd; } ;
struct TYPE_2__ {int /*<<< orphan*/  device; } ;

/* Variables and functions */
 void* scsi_target (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ibmvfc_match_target(struct ibmvfc_event *evt, void *device)
{
	if (evt->cmnd && scsi_target(evt->cmnd->device) == device)
		return 1;
	return 0;
}