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
struct mmc_host {struct cqhci_host* cqe_private; } ;
struct cqhci_host {int /*<<< orphan*/  wait_queue; } ;

/* Variables and functions */
 int /*<<< orphan*/  CQHCI_CLEAR_ALL_TASKS ; 
 int /*<<< orphan*/  CQHCI_CTL ; 
 int /*<<< orphan*/  CQHCI_IS_TCL ; 
 int /*<<< orphan*/  cqhci_readl (struct cqhci_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cqhci_set_irqs (struct cqhci_host*,int /*<<< orphan*/ ) ; 
 int cqhci_tasks_cleared (struct cqhci_host*) ; 
 int /*<<< orphan*/  cqhci_writel (struct cqhci_host*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_hostname (struct mmc_host*) ; 
 scalar_t__ msecs_to_jiffies (unsigned int) ; 
 int /*<<< orphan*/  pr_debug (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wait_event_timeout (int /*<<< orphan*/ ,int,scalar_t__) ; 

__attribute__((used)) static bool cqhci_clear_all_tasks(struct mmc_host *mmc, unsigned int timeout)
{
	struct cqhci_host *cq_host = mmc->cqe_private;
	bool ret;
	u32 ctl;

	cqhci_set_irqs(cq_host, CQHCI_IS_TCL);

	ctl = cqhci_readl(cq_host, CQHCI_CTL);
	ctl |= CQHCI_CLEAR_ALL_TASKS;
	cqhci_writel(cq_host, ctl, CQHCI_CTL);

	wait_event_timeout(cq_host->wait_queue, cqhci_tasks_cleared(cq_host),
			   msecs_to_jiffies(timeout) + 1);

	cqhci_set_irqs(cq_host, 0);

	ret = cqhci_tasks_cleared(cq_host);

	if (!ret)
		pr_debug("%s: cqhci: Failed to clear tasks\n",
			 mmc_hostname(mmc));

	return ret;
}