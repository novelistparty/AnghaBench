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
struct snd_cs46xx {int /*<<< orphan*/  midcr; } ;

/* Variables and functions */
 int /*<<< orphan*/  BA0_MIDCR ; 
 int /*<<< orphan*/  MIDCR_MRST ; 
 int /*<<< orphan*/  snd_cs46xx_pokeBA0 (struct snd_cs46xx*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void snd_cs46xx_midi_reset(struct snd_cs46xx *chip)
{
	snd_cs46xx_pokeBA0(chip, BA0_MIDCR, MIDCR_MRST);
	udelay(100);
	snd_cs46xx_pokeBA0(chip, BA0_MIDCR, chip->midcr);
}