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
struct TYPE_3__ {unsigned long data; int /*<<< orphan*/  func; } ;
struct TYPE_4__ {int /*<<< orphan*/  wait_q; TYPE_1__ irq_tasklet; } ;
struct lcs_card {TYPE_2__ read; } ;

/* Variables and functions */
 int /*<<< orphan*/  LCS_DBF_TEXT (int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lcs_setup_read_ccws (struct lcs_card*) ; 
 int /*<<< orphan*/  lcs_tasklet ; 
 int /*<<< orphan*/  setup ; 

__attribute__((used)) static void
lcs_setup_read(struct lcs_card *card)
{
	LCS_DBF_TEXT(3, setup, "initread");

	lcs_setup_read_ccws(card);
	/* Initialize read channel tasklet. */
	card->read.irq_tasklet.data = (unsigned long) &card->read;
	card->read.irq_tasklet.func = lcs_tasklet;
	/* Initialize waitqueue. */
	init_waitqueue_head(&card->read.wait_q);
}