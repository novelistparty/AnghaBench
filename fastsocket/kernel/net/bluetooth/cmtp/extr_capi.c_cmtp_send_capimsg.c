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
struct sk_buff {int /*<<< orphan*/  data; int /*<<< orphan*/  len; scalar_t__ cb; } ;
struct cmtp_session {int /*<<< orphan*/  transmit; } ;
struct cmtp_scb {int id; int data; } ;

/* Variables and functions */
 int /*<<< orphan*/  BT_DBG (char*,struct cmtp_session*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 scalar_t__ CAPIMSG_COMMAND (int /*<<< orphan*/ ) ; 
 scalar_t__ CAPI_DATA_B3 ; 
 int /*<<< orphan*/  cmtp_schedule (struct cmtp_session*) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 

__attribute__((used)) static void cmtp_send_capimsg(struct cmtp_session *session, struct sk_buff *skb)
{
	struct cmtp_scb *scb = (void *) skb->cb;

	BT_DBG("session %p skb %p len %d", session, skb, skb->len);

	scb->id = -1;
	scb->data = (CAPIMSG_COMMAND(skb->data) == CAPI_DATA_B3);

	skb_queue_tail(&session->transmit, skb);

	cmtp_schedule(session);
}