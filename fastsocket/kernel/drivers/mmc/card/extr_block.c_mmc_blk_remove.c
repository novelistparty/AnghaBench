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
struct mmc_card {int dummy; } ;
struct mmc_blk_data {int /*<<< orphan*/  queue; int /*<<< orphan*/  disk; } ;

/* Variables and functions */
 int /*<<< orphan*/  del_gendisk (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_blk_put (struct mmc_blk_data*) ; 
 int /*<<< orphan*/  mmc_cleanup_queue (int /*<<< orphan*/ *) ; 
 struct mmc_blk_data* mmc_get_drvdata (struct mmc_card*) ; 
 int /*<<< orphan*/  mmc_set_drvdata (struct mmc_card*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void mmc_blk_remove(struct mmc_card *card)
{
	struct mmc_blk_data *md = mmc_get_drvdata(card);

	if (md) {
		/* Stop new requests from getting into the queue */
		del_gendisk(md->disk);

		/* Then flush out any already in there */
		mmc_cleanup_queue(&md->queue);

		mmc_blk_put(md);
	}
	mmc_set_drvdata(card, NULL);
}