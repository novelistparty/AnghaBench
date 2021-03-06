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
struct ata_link {int dummy; } ;
struct TYPE_4__ {int probe_mask; int /*<<< orphan*/  action; } ;
struct ata_eh_context {int did_probe_mask; int saved_ncq_enabled; scalar_t__* saved_xfer_mode; TYPE_2__ i; } ;
struct ata_device {int devno; int /*<<< orphan*/  ering; TYPE_1__* link; } ;
struct TYPE_3__ {struct ata_eh_context eh_context; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC_ERR_OTHER ; 
 int ATA_EH_PROBE_TRIALS ; 
 int /*<<< orphan*/  ATA_EH_RESET ; 
 int /*<<< orphan*/  ata_count_probe_trials_cb ; 
 int /*<<< orphan*/  ata_dev_init (struct ata_device*) ; 
 struct ata_link* ata_dev_phys_link (struct ata_device*) ; 
 int /*<<< orphan*/  ata_eh_detach_dev (struct ata_device*) ; 
 int /*<<< orphan*/  ata_ering_map (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  ata_ering_record (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sata_down_spd_limit (struct ata_link*,int) ; 

__attribute__((used)) static int ata_eh_schedule_probe(struct ata_device *dev)
{
	struct ata_eh_context *ehc = &dev->link->eh_context;
	struct ata_link *link = ata_dev_phys_link(dev);
	int trials = 0;

	if (!(ehc->i.probe_mask & (1 << dev->devno)) ||
	    (ehc->did_probe_mask & (1 << dev->devno)))
		return 0;

	ata_eh_detach_dev(dev);
	ata_dev_init(dev);
	ehc->did_probe_mask |= (1 << dev->devno);
	ehc->i.action |= ATA_EH_RESET;
	ehc->saved_xfer_mode[dev->devno] = 0;
	ehc->saved_ncq_enabled &= ~(1 << dev->devno);

	/* Record and count probe trials on the ering.  The specific
	 * error mask used is irrelevant.  Because a successful device
	 * detection clears the ering, this count accumulates only if
	 * there are consecutive failed probes.
	 *
	 * If the count is equal to or higher than ATA_EH_PROBE_TRIALS
	 * in the last ATA_EH_PROBE_TRIAL_INTERVAL, link speed is
	 * forced to 1.5Gbps.
	 *
	 * This is to work around cases where failed link speed
	 * negotiation results in device misdetection leading to
	 * infinite DEVXCHG or PHRDY CHG events.
	 */
	ata_ering_record(&dev->ering, 0, AC_ERR_OTHER);
	ata_ering_map(&dev->ering, ata_count_probe_trials_cb, &trials);

	if (trials > ATA_EH_PROBE_TRIALS)
		sata_down_spd_limit(link, 1);

	return 1;
}