#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tBTA_SET_ADV_DATA_CMPL_CBACK ;
struct TYPE_4__ {int /*<<< orphan*/  event; } ;
struct TYPE_5__ {scalar_t__ raw_adv_len; int /*<<< orphan*/ * p_raw_adv; int /*<<< orphan*/ * p_adv_data_cback; TYPE_1__ hdr; } ;
typedef  TYPE_2__ tBTA_DM_API_SET_ADV_CONFIG_RAW ;
typedef  int /*<<< orphan*/  UINT8 ;
typedef  scalar_t__ UINT32 ;

/* Variables and functions */
 int /*<<< orphan*/  BTA_DM_API_BLE_SET_ADV_CONFIG_RAW_EVT ; 
 int /*<<< orphan*/  bta_sys_sendmsg (TYPE_2__*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ osi_malloc (scalar_t__) ; 

void BTA_DmBleSetAdvConfigRaw (UINT8 *p_raw_adv, UINT32 raw_adv_len,
                            tBTA_SET_ADV_DATA_CMPL_CBACK *p_adv_data_cback)
{
    tBTA_DM_API_SET_ADV_CONFIG_RAW  *p_msg;

    if ((p_msg = (tBTA_DM_API_SET_ADV_CONFIG_RAW *)
                 osi_malloc(sizeof(tBTA_DM_API_SET_ADV_CONFIG_RAW) + raw_adv_len)) != NULL) {
        p_msg->hdr.event = BTA_DM_API_BLE_SET_ADV_CONFIG_RAW_EVT;
        p_msg->p_adv_data_cback = p_adv_data_cback;
        p_msg->p_raw_adv = (UINT8 *)(p_msg + 1);
        memcpy(p_msg->p_raw_adv, p_raw_adv, raw_adv_len);
        p_msg->raw_adv_len = raw_adv_len;

        bta_sys_sendmsg(p_msg);
    }
}