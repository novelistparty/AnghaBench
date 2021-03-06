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
 int /*<<< orphan*/  AK5558_02_CONTROL1 ; 
 int /*<<< orphan*/  AK5558_CKS ; 
 int /*<<< orphan*/  AK5558_CKS_AUTO ; 
 int snd_soc_component_update_bits (struct snd_soc_component*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ak5558_set_mcki(struct snd_soc_component *component)
{
	return snd_soc_component_update_bits(component, AK5558_02_CONTROL1, AK5558_CKS,
				   AK5558_CKS_AUTO);
}