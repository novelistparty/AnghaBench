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
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 int /*<<< orphan*/  exc_action_label_init ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 

struct label *
mac_exc_create_label(void)
{
	struct label *label = mac_labelzone_alloc(MAC_WAITOK);

	if (label == NULL) {
		return NULL;
	}

	// Policy initialization of the label, typically performs allocations as well.
	// (Unless the policy's full data really fits into a pointer size.)
	MAC_PERFORM(exc_action_label_init, label);
	
	return label;
}