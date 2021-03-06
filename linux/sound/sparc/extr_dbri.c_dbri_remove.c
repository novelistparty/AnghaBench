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
struct snd_card {int /*<<< orphan*/  private_data; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 struct snd_card* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_card_free (struct snd_card*) ; 
 int /*<<< orphan*/  snd_dbri_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dbri_remove(struct platform_device *op)
{
	struct snd_card *card = dev_get_drvdata(&op->dev);

	snd_dbri_free(card->private_data);
	snd_card_free(card);

	return 0;
}