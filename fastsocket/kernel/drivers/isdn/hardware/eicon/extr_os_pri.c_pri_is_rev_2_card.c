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

/* Variables and functions */
#define  CARDTYPE_DIVASRV_P_30M_V2_PCI 129 
#define  CARDTYPE_DIVASRV_VOICE_P_30M_V2_PCI 128 

__attribute__((used)) static int pri_is_rev_2_card(int card_ordinal)
{
	switch (card_ordinal) {
	case CARDTYPE_DIVASRV_P_30M_V2_PCI:
	case CARDTYPE_DIVASRV_VOICE_P_30M_V2_PCI:
		return (1);
	}
	return (0);
}