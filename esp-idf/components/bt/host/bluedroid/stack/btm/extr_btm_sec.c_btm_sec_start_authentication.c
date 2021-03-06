#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  hci_handle; int /*<<< orphan*/  sec_state; } ;
typedef  TYPE_1__ tBTM_SEC_DEV_REC ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  BTM_SEC_STATE_AUTHENTICATING ; 
 int /*<<< orphan*/  btsnd_hcic_auth_request (int /*<<< orphan*/ ) ; 

__attribute__((used)) static BOOLEAN btm_sec_start_authentication (tBTM_SEC_DEV_REC *p_dev_rec)
{
    p_dev_rec->sec_state = BTM_SEC_STATE_AUTHENTICATING;

    return (btsnd_hcic_auth_request (p_dev_rec->hci_handle));
}