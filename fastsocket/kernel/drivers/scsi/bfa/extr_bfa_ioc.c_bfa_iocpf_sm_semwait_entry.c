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
struct bfa_iocpf_s {int /*<<< orphan*/  ioc; } ;

/* Variables and functions */
 int /*<<< orphan*/  bfa_ioc_hw_sem_get (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
bfa_iocpf_sm_semwait_entry(struct bfa_iocpf_s *iocpf)
{
	bfa_ioc_hw_sem_get(iocpf->ioc);
}