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
struct snd_maya44 {int /*<<< orphan*/  ice; } ;
struct snd_kcontrol {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/ * item; } ;
struct TYPE_4__ {TYPE_1__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_2__ value; int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int /*<<< orphan*/  maya_pb_route_shift (int) ; 
 int snd_ctl_get_ioffidx (struct snd_kcontrol*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_ice1724_get_route_val (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct snd_maya44* snd_kcontrol_chip (struct snd_kcontrol*) ; 

__attribute__((used)) static int maya_pb_route_get(struct snd_kcontrol *kcontrol,
			     struct snd_ctl_elem_value *ucontrol)
{
	struct snd_maya44 *chip = snd_kcontrol_chip(kcontrol);
	int idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
	ucontrol->value.enumerated.item[0] =
		snd_ice1724_get_route_val(chip->ice, maya_pb_route_shift(idx));
	return 0;
}