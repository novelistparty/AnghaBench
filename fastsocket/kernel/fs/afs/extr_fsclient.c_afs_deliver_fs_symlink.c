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
struct sk_buff {int /*<<< orphan*/  len; } ;
struct afs_vnode {int /*<<< orphan*/  status; } ;
struct afs_call {scalar_t__ reply_size; scalar_t__ reply_max; int /*<<< orphan*/ * reply3; int /*<<< orphan*/  reply2; int /*<<< orphan*/ * buffer; int /*<<< orphan*/  unmarshall; struct afs_vnode* reply; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int EBADMSG ; 
 int /*<<< orphan*/  _enter (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  _leave (char*) ; 
 int /*<<< orphan*/  afs_transfer_reply (struct afs_call*,struct sk_buff*) ; 
 int /*<<< orphan*/  xdr_decode_AFSFetchStatus (int /*<<< orphan*/  const**,int /*<<< orphan*/ *,struct afs_vnode*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xdr_decode_AFSFid (int /*<<< orphan*/  const**,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int afs_deliver_fs_symlink(struct afs_call *call,
				  struct sk_buff *skb, bool last)
{
	struct afs_vnode *vnode = call->reply;
	const __be32 *bp;

	_enter("{%u},{%u},%d", call->unmarshall, skb->len, last);

	afs_transfer_reply(call, skb);
	if (!last)
		return 0;

	if (call->reply_size != call->reply_max)
		return -EBADMSG;

	/* unmarshall the reply once we've received all of it */
	bp = call->buffer;
	xdr_decode_AFSFid(&bp, call->reply2);
	xdr_decode_AFSFetchStatus(&bp, call->reply3, NULL, NULL);
	xdr_decode_AFSFetchStatus(&bp, &vnode->status, vnode, NULL);
	/* xdr_decode_AFSVolSync(&bp, call->replyX); */

	_leave(" = 0 [done]");
	return 0;
}