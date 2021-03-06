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
struct rfcomm_session {int dummy; } ;
struct rfcomm_dlc {int state; int /*<<< orphan*/  tx_queue; int /*<<< orphan*/  (* state_change ) (struct rfcomm_dlc*,int) ;int /*<<< orphan*/  flags; int /*<<< orphan*/  dlci; struct rfcomm_session* session; } ;

/* Variables and functions */
 int BT_CLOSED ; 
#define  BT_CONFIG 132 
#define  BT_CONNECT 131 
#define  BT_CONNECT2 130 
#define  BT_CONNECTED 129 
 int /*<<< orphan*/  BT_DBG (char*,struct rfcomm_dlc*,int,int /*<<< orphan*/ ,int,struct rfcomm_session*) ; 
 int BT_DISCONN ; 
#define  BT_OPEN 128 
 int /*<<< orphan*/  RFCOMM_AUTH_REJECT ; 
 int /*<<< orphan*/  RFCOMM_DEFER_SETUP ; 
 int RFCOMM_DISC_TIMEOUT ; 
 int /*<<< orphan*/  RFCOMM_SCHED_AUTH ; 
 int /*<<< orphan*/  rfcomm_dlc_clear_timer (struct rfcomm_dlc*) ; 
 int /*<<< orphan*/  rfcomm_dlc_lock (struct rfcomm_dlc*) ; 
 int /*<<< orphan*/  rfcomm_dlc_set_timer (struct rfcomm_dlc*,int) ; 
 int /*<<< orphan*/  rfcomm_dlc_unlink (struct rfcomm_dlc*) ; 
 int /*<<< orphan*/  rfcomm_dlc_unlock (struct rfcomm_dlc*) ; 
 int /*<<< orphan*/  rfcomm_queue_disc (struct rfcomm_dlc*) ; 
 int /*<<< orphan*/  rfcomm_schedule (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rfcomm_send_disc (struct rfcomm_session*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_queue_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_queue_purge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct rfcomm_dlc*,int) ; 
 int /*<<< orphan*/  test_and_clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int __rfcomm_dlc_close(struct rfcomm_dlc *d, int err)
{
	struct rfcomm_session *s = d->session;
	if (!s)
		return 0;

	BT_DBG("dlc %p state %ld dlci %d err %d session %p",
			d, d->state, d->dlci, err, s);

	switch (d->state) {
	case BT_CONNECT:
	case BT_CONFIG:
		if (test_and_clear_bit(RFCOMM_DEFER_SETUP, &d->flags)) {
			set_bit(RFCOMM_AUTH_REJECT, &d->flags);
			rfcomm_schedule(RFCOMM_SCHED_AUTH);
			break;
		}
		/* Fall through */

	case BT_CONNECTED:
		d->state = BT_DISCONN;
		if (skb_queue_empty(&d->tx_queue)) {
			rfcomm_send_disc(s, d->dlci);
			rfcomm_dlc_set_timer(d, RFCOMM_DISC_TIMEOUT);
		} else {
			rfcomm_queue_disc(d);
			rfcomm_dlc_set_timer(d, RFCOMM_DISC_TIMEOUT * 2);
		}
		break;

	case BT_OPEN:
	case BT_CONNECT2:
		if (test_and_clear_bit(RFCOMM_DEFER_SETUP, &d->flags)) {
			set_bit(RFCOMM_AUTH_REJECT, &d->flags);
			rfcomm_schedule(RFCOMM_SCHED_AUTH);
			break;
		}
		/* Fall through */

	default:
		rfcomm_dlc_clear_timer(d);

		rfcomm_dlc_lock(d);
		d->state = BT_CLOSED;
		d->state_change(d, err);
		rfcomm_dlc_unlock(d);

		skb_queue_purge(&d->tx_queue);
		rfcomm_dlc_unlink(d);
	}

	return 0;
}