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
struct cvm_mmc_host {int /*<<< orphan*/  mmc_serializer; } ;

/* Variables and functions */
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void thunder_mmc_release_bus(struct cvm_mmc_host *host)
{
	up(&host->mmc_serializer);
}