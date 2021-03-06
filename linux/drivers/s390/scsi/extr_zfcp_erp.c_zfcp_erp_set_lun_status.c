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
typedef  int /*<<< orphan*/  u32 ;
struct zfcp_scsi_dev {int /*<<< orphan*/  status; } ;
struct scsi_device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  atomic_or (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct zfcp_scsi_dev* sdev_to_zfcp (struct scsi_device*) ; 

void zfcp_erp_set_lun_status(struct scsi_device *sdev, u32 mask)
{
	struct zfcp_scsi_dev *zfcp_sdev = sdev_to_zfcp(sdev);

	atomic_or(mask, &zfcp_sdev->status);
}