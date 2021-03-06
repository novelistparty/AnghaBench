#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int* resp; int /*<<< orphan*/  error; } ;
struct TYPE_3__ {int /*<<< orphan*/  error; } ;
struct mmc_blk_request {TYPE_2__ cmd; TYPE_1__ sbc; } ;

/* Variables and functions */
 int CMD_ERRORS ; 

__attribute__((used)) static inline bool mmc_blk_cmd_started(struct mmc_blk_request *brq)
{
	return !brq->sbc.error && !brq->cmd.error &&
	       !(brq->cmd.resp[0] & CMD_ERRORS);
}