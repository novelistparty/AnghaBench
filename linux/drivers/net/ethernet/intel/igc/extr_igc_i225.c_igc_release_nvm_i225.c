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
struct igc_hw {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IGC_SWFW_EEP_SM ; 
 int /*<<< orphan*/  igc_release_swfw_sync_i225 (struct igc_hw*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void igc_release_nvm_i225(struct igc_hw *hw)
{
	igc_release_swfw_sync_i225(hw, IGC_SWFW_EEP_SM);
}