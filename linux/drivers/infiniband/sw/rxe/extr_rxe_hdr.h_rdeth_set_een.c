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
typedef  int /*<<< orphan*/  u32 ;
struct rxe_pkt_info {size_t opcode; scalar_t__ offset; scalar_t__ hdr; } ;
struct TYPE_2__ {scalar_t__* offset; } ;

/* Variables and functions */
 size_t RXE_RDETH ; 
 int /*<<< orphan*/  __rdeth_set_een (scalar_t__,int /*<<< orphan*/ ) ; 
 TYPE_1__* rxe_opcode ; 

__attribute__((used)) static inline void rdeth_set_een(struct rxe_pkt_info *pkt, u32 een)
{
	__rdeth_set_een(pkt->hdr + pkt->offset
		+ rxe_opcode[pkt->opcode].offset[RXE_RDETH], een);
}