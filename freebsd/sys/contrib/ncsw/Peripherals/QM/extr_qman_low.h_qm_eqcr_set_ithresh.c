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
typedef  int /*<<< orphan*/  uint8_t ;
struct qm_eqcr {int /*<<< orphan*/  ithresh; } ;
struct qm_portal {struct qm_eqcr eqcr; } ;

/* Variables and functions */
 int /*<<< orphan*/  EQCR_ITR ; 
 int /*<<< orphan*/  qm_out (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline__ void qm_eqcr_set_ithresh(struct qm_portal *portal, uint8_t ithresh)
{
    register struct qm_eqcr *eqcr = &portal->eqcr;
    eqcr->ithresh = ithresh;
    qm_out(EQCR_ITR, ithresh);
}