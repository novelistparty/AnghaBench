#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u32 ;
struct TYPE_7__ {int /*<<< orphan*/  seqid; } ;
struct nfs4_state {int /*<<< orphan*/  seqlock; TYPE_4__ open_stateid; } ;
typedef  scalar_t__ s32 ;
struct TYPE_6__ {int /*<<< orphan*/  seqid; } ;
typedef  TYPE_1__ nfs4_stateid ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfs4_state_match_open_stateid_other (struct nfs4_state*,TYPE_1__*) ; 
 int /*<<< orphan*/  nfs4_stateid_copy (TYPE_1__*,TYPE_4__*) ; 
 int /*<<< orphan*/  nfs4_valid_open_stateid (struct nfs4_state*) ; 
 int read_seqbegin (int /*<<< orphan*/ *) ; 
 scalar_t__ read_seqretry (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void nfs4_sync_open_stateid(nfs4_stateid *dst,
		struct nfs4_state *state)
{
	__be32 seqid_open;
	u32 dst_seqid;
	int seq;

	for (;;) {
		if (!nfs4_valid_open_stateid(state))
			break;
		seq = read_seqbegin(&state->seqlock);
		if (!nfs4_state_match_open_stateid_other(state, dst)) {
			nfs4_stateid_copy(dst, &state->open_stateid);
			if (read_seqretry(&state->seqlock, seq))
				continue;
			break;
		}
		seqid_open = state->open_stateid.seqid;
		if (read_seqretry(&state->seqlock, seq))
			continue;

		dst_seqid = be32_to_cpu(dst->seqid);
		if ((s32)(dst_seqid - be32_to_cpu(seqid_open)) < 0)
			dst->seqid = seqid_open;
		break;
	}
}