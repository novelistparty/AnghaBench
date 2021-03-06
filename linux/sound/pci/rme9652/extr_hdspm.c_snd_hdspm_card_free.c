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
struct snd_card {struct hdspm* private_data; } ;
struct hdspm {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  snd_hdspm_free (struct hdspm*) ; 

__attribute__((used)) static void snd_hdspm_card_free(struct snd_card *card)
{
	struct hdspm *hdspm = card->private_data;

	if (hdspm)
		snd_hdspm_free(hdspm);
}