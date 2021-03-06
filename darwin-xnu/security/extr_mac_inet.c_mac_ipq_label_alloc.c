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
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,struct label*,int) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*) ; 
 int /*<<< orphan*/  ipq_label_destroy ; 
 int /*<<< orphan*/  ipq_label_init ; 
 struct label* mac_labelzone_alloc (int) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 

__attribute__((used)) static struct label *
mac_ipq_label_alloc(int flag)
{
	struct label *label;
	int error;

	label = mac_labelzone_alloc(flag);
	if (label == NULL)
		return (NULL);

	MAC_CHECK(ipq_label_init, label, flag);
	if (error) {
		MAC_PERFORM(ipq_label_destroy, label);
		mac_labelzone_free(label);
		return (NULL);
	}
	return (label);
}