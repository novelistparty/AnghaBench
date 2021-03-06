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
struct scsi_device {int queue_depth; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int IBMVFC_MAX_CMDS_PER_LUN ; 
 int SCSI_QDEPTH_DEFAULT ; 
 int /*<<< orphan*/  scsi_adjust_queue_depth (struct scsi_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int ibmvfc_change_queue_depth(struct scsi_device *sdev, int qdepth,
				     int reason)
{
	if (reason != SCSI_QDEPTH_DEFAULT)
		return -EOPNOTSUPP;

	if (qdepth > IBMVFC_MAX_CMDS_PER_LUN)
		qdepth = IBMVFC_MAX_CMDS_PER_LUN;

	scsi_adjust_queue_depth(sdev, 0, qdepth);
	return sdev->queue_depth;
}