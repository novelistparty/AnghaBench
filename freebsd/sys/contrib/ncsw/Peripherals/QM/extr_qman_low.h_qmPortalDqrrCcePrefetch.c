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
struct qm_dqrr {scalar_t__ cmode; } ;
struct qm_portal {struct qm_dqrr dqrr; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_COND (int) ; 
 int /*<<< orphan*/  DQRR_CI ; 
 scalar_t__ e_QmPortalDqrrCCE ; 
 int /*<<< orphan*/  qm_cl_invalidate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  qm_cl_touch_rw (int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline__ void qmPortalDqrrCcePrefetch(struct qm_portal *portal)
{
#ifdef QM_CHECKING
    register struct qm_dqrr *dqrr = &portal->dqrr;
    ASSERT_COND(dqrr->cmode == e_QmPortalDqrrCCE);
#endif /* QM_CHECKING */
    qm_cl_invalidate(DQRR_CI);
    qm_cl_touch_rw(DQRR_CI);
}