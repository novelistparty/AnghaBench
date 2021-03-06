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
struct nfs_client {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  nfs40_handle_cb_pathdown (struct nfs_client*) ; 
 int /*<<< orphan*/  nfs4_schedule_state_manager (struct nfs_client*) ; 

void nfs4_schedule_path_down_recovery(struct nfs_client *clp)
{
	nfs40_handle_cb_pathdown(clp);
	nfs4_schedule_state_manager(clp);
}