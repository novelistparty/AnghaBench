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
struct eap_vendor_test_data {int state; } ;

/* Variables and functions */
 int /*<<< orphan*/  MSG_DEBUG ; 
 int /*<<< orphan*/  eap_vendor_test_state_txt (int) ; 
 int /*<<< orphan*/  wpa_printf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void eap_vendor_test_state(struct eap_vendor_test_data *data,
				  int state)
{
	wpa_printf(MSG_DEBUG, "EAP-VENDOR-TEST: %s -> %s",
		   eap_vendor_test_state_txt(data->state),
		   eap_vendor_test_state_txt(state));
	data->state = state;
}