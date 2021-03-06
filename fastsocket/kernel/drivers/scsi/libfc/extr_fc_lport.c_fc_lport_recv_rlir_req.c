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
struct TYPE_2__ {int /*<<< orphan*/  (* seq_els_rsp_send ) (struct fc_frame*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ;} ;
struct fc_lport {TYPE_1__ tt; } ;
struct fc_frame {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ELS_LS_ACC ; 
 int /*<<< orphan*/  FC_LPORT_DBG (struct fc_lport*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_frame_free (struct fc_frame*) ; 
 int /*<<< orphan*/  fc_lport_state (struct fc_lport*) ; 
 int /*<<< orphan*/  stub1 (struct fc_frame*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void fc_lport_recv_rlir_req(struct fc_lport *lport, struct fc_frame *fp)
{
	FC_LPORT_DBG(lport, "Received RLIR request while in state %s\n",
		     fc_lport_state(lport));

	lport->tt.seq_els_rsp_send(fp, ELS_LS_ACC, NULL);
	fc_frame_free(fp);
}