#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  btc_hf_client_cb_t ;
struct TYPE_2__ {int /*<<< orphan*/  btc_hf_client_cb; } ;

/* Variables and functions */
 TYPE_1__ hf_client_local_param ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void clear_state(void)
{
    memset(&hf_client_local_param.btc_hf_client_cb, 0, sizeof(btc_hf_client_cb_t));
}