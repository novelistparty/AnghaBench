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
struct scsi_host_template {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  desc; } ;
struct TYPE_3__ {TYPE_2__ eh_info; } ;
struct ata_port {scalar_t__ cbl; int flags; TYPE_1__ link; int /*<<< orphan*/  udma_mask; int /*<<< orphan*/  mwdma_mask; int /*<<< orphan*/  pio_mask; TYPE_1__* slave_link; int /*<<< orphan*/  print_id; } ;
struct ata_host {int flags; int n_ports; struct ata_port** ports; int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 scalar_t__ ATA_CBL_NONE ; 
 scalar_t__ ATA_CBL_SATA ; 
 int ATA_FLAG_SATA ; 
 int ATA_HOST_STARTED ; 
 int EINVAL ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  KERN_INFO ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  async_port_probe ; 
 int /*<<< orphan*/  async_schedule (int /*<<< orphan*/ ,struct ata_port*) ; 
 int /*<<< orphan*/  ata_acpi_associate (struct ata_host*) ; 
 int /*<<< orphan*/  ata_ehi_clear_desc (TYPE_2__*) ; 
 int /*<<< orphan*/  ata_mode_string (unsigned long) ; 
 unsigned long ata_pack_xfermask (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ata_port_is_dummy (struct ata_port*) ; 
 int /*<<< orphan*/  ata_port_printk (struct ata_port*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ata_print_id ; 
 int ata_scsi_add_hosts (struct ata_host*,struct scsi_host_template*) ; 
 int /*<<< orphan*/  atomic_inc_return (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_printk (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  kfree (struct ata_port*) ; 
 int /*<<< orphan*/  sata_link_init_spd (TYPE_1__*) ; 

int ata_host_register(struct ata_host *host, struct scsi_host_template *sht)
{
	int i, rc;

	/* host must have been started */
	if (!(host->flags & ATA_HOST_STARTED)) {
		dev_printk(KERN_ERR, host->dev,
			   "BUG: trying to register unstarted host\n");
		WARN_ON(1);
		return -EINVAL;
	}

	/* Blow away unused ports.  This happens when LLD can't
	 * determine the exact number of ports to allocate at
	 * allocation time.
	 */
	for (i = host->n_ports; host->ports[i]; i++)
		kfree(host->ports[i]);

	/* give ports names and add SCSI hosts */
	for (i = 0; i < host->n_ports; i++)
		host->ports[i]->print_id = atomic_inc_return(&ata_print_id);

	rc = ata_scsi_add_hosts(host, sht);
	if (rc)
		return rc;

	/* associate with ACPI nodes */
	ata_acpi_associate(host);

	/* set cable, sata_spd_limit and report */
	for (i = 0; i < host->n_ports; i++) {
		struct ata_port *ap = host->ports[i];
		unsigned long xfer_mask;

		/* set SATA cable type if still unset */
		if (ap->cbl == ATA_CBL_NONE && (ap->flags & ATA_FLAG_SATA))
			ap->cbl = ATA_CBL_SATA;

		/* init sata_spd_limit to the current value */
		sata_link_init_spd(&ap->link);
		if (ap->slave_link)
			sata_link_init_spd(ap->slave_link);

		/* print per-port info to dmesg */
		xfer_mask = ata_pack_xfermask(ap->pio_mask, ap->mwdma_mask,
					      ap->udma_mask);

		if (!ata_port_is_dummy(ap)) {
			ata_port_printk(ap, KERN_INFO,
					"%cATA max %s %s\n",
					(ap->flags & ATA_FLAG_SATA) ? 'S' : 'P',
					ata_mode_string(xfer_mask),
					ap->link.eh_info.desc);
			ata_ehi_clear_desc(&ap->link.eh_info);
		} else
			ata_port_printk(ap, KERN_INFO, "DUMMY\n");
	}

	/* perform each probe asynchronously */
	for (i = 0; i < host->n_ports; i++) {
		struct ata_port *ap = host->ports[i];
		async_schedule(async_port_probe, ap);
	}

	return 0;
}