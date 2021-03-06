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
struct scsi_qla_host {TYPE_1__* iobase; } ;
struct TYPE_2__ {int /*<<< orphan*/  ictrl; } ;

/* Variables and functions */
 int /*<<< orphan*/  RD_REG_WORD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WRT_REG_WORD (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
qla1280_disable_intrs(struct scsi_qla_host *ha)
{
	WRT_REG_WORD(&ha->iobase->ictrl, 0);
	RD_REG_WORD(&ha->iobase->ictrl);	/* PCI Posted Write flush */
}