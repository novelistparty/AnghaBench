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
typedef  int /*<<< orphan*/  CONFIG_PAGE_SCSI_DEVICE_1 ;

/* Variables and functions */
 int /*<<< orphan*/  Configuration ; 
 int /*<<< orphan*/  MPT_2_HOST32 (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RequestedParameters ; 
 int /*<<< orphan*/  Reserved ; 

void
mpt2host_config_page_scsi_device_1(CONFIG_PAGE_SCSI_DEVICE_1 *sd1)
{

	MPT_2_HOST32(sd1, RequestedParameters);
	MPT_2_HOST32(sd1, Reserved);
	MPT_2_HOST32(sd1, Configuration);
}