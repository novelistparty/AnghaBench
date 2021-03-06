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
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int* item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct cmipci {int /*<<< orphan*/  reg_lock; } ;

/* Variables and functions */
 int CM_BASE2LIN ; 
 int CM_CENTR2LIN ; 
 int /*<<< orphan*/  CM_REAR2LIN ; 
 int /*<<< orphan*/  CM_REG_LEGACY_CTRL ; 
 int /*<<< orphan*/  CM_REG_MIXER1 ; 
 int snd_cmipci_clear_bit (struct cmipci*,int /*<<< orphan*/ ,int) ; 
 int snd_cmipci_clear_bit_b (struct cmipci*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_cmipci_set_bit (struct cmipci*,int /*<<< orphan*/ ,int) ; 
 int snd_cmipci_set_bit_b (struct cmipci*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct cmipci* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int snd_cmipci_line_in_mode_put(struct snd_kcontrol *kcontrol,
				       struct snd_ctl_elem_value *ucontrol)
{
	struct cmipci *cm = snd_kcontrol_chip(kcontrol);
	int change;

	spin_lock_irq(&cm->reg_lock);
	if (ucontrol->value.enumerated.item[0] == 2)
		change = snd_cmipci_set_bit(cm, CM_REG_LEGACY_CTRL, CM_CENTR2LIN | CM_BASE2LIN);
	else
		change = snd_cmipci_clear_bit(cm, CM_REG_LEGACY_CTRL, CM_CENTR2LIN | CM_BASE2LIN);
	if (ucontrol->value.enumerated.item[0] == 1)
		change |= snd_cmipci_set_bit_b(cm, CM_REG_MIXER1, CM_REAR2LIN);
	else
		change |= snd_cmipci_clear_bit_b(cm, CM_REG_MIXER1, CM_REAR2LIN);
	spin_unlock_irq(&cm->reg_lock);
	return change;
}