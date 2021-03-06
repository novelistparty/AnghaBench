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
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  dsl_pool_t ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  B_TRUE ; 
 int /*<<< orphan*/  txg_wait_synced_impl (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

boolean_t
txg_wait_synced_sig(dsl_pool_t *dp, uint64_t txg)
{
	return (txg_wait_synced_impl(dp, txg, B_TRUE));
}