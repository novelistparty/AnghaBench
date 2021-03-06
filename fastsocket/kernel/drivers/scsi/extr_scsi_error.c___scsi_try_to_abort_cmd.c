#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct scsi_cmnd {TYPE_3__* device; } ;
struct TYPE_6__ {TYPE_2__* host; } ;
struct TYPE_5__ {TYPE_1__* hostt; } ;
struct TYPE_4__ {int (* eh_abort_handler ) (struct scsi_cmnd*) ;} ;

/* Variables and functions */
 int FAILED ; 
 int stub1 (struct scsi_cmnd*) ; 

__attribute__((used)) static int __scsi_try_to_abort_cmd(struct scsi_cmnd *scmd)
{
	if (!scmd->device->host->hostt->eh_abort_handler)
		return FAILED;

	return scmd->device->host->hostt->eh_abort_handler(scmd);
}