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
struct bhnd_nvram_data {int dummy; } ;
struct bhnd_nvram_bcm {int /*<<< orphan*/ * opts; } ;
typedef  int /*<<< orphan*/  bhnd_nvram_plist ;

/* Variables and functions */

__attribute__((used)) static bhnd_nvram_plist *
bhnd_nvram_bcm_options(struct bhnd_nvram_data *nv)
{
	struct bhnd_nvram_bcm *bcm = (struct bhnd_nvram_bcm *)nv;
	return (bcm->opts);
}