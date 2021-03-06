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
struct hdac_device {int dummy; } ;
typedef  int /*<<< orphan*/  hda_nid_t ;

/* Variables and functions */
 int /*<<< orphan*/  AC_VERB_PARAMETERS ; 
 int snd_hdac_regmap_encode_verb (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int snd_hdac_regmap_read_raw (struct hdac_device*,unsigned int,unsigned int*) ; 

int _snd_hdac_read_parm(struct hdac_device *codec, hda_nid_t nid, int parm,
			unsigned int *res)
{
	unsigned int cmd;

	cmd = snd_hdac_regmap_encode_verb(nid, AC_VERB_PARAMETERS) | parm;
	return snd_hdac_regmap_read_raw(codec, cmd, res);
}