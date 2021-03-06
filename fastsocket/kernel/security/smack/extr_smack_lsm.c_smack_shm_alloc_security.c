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
struct kern_ipc_perm {int /*<<< orphan*/  security; } ;
struct shmid_kernel {struct kern_ipc_perm shm_perm; } ;

/* Variables and functions */
 int /*<<< orphan*/  current_security () ; 

__attribute__((used)) static int smack_shm_alloc_security(struct shmid_kernel *shp)
{
	struct kern_ipc_perm *isp = &shp->shm_perm;

	isp->security = current_security();
	return 0;
}