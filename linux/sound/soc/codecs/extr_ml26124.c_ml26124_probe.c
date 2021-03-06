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
struct snd_soc_component {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ML26124_SW_RST ; 
 int /*<<< orphan*/  snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int ml26124_probe(struct snd_soc_component *component)
{
	/* Software Reset */
	snd_soc_component_update_bits(component, ML26124_SW_RST, 0x01, 1);
	snd_soc_component_update_bits(component, ML26124_SW_RST, 0x01, 0);

	return 0;
}