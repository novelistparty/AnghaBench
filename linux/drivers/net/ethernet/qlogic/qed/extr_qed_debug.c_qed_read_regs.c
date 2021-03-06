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
typedef  size_t u32 ;
struct qed_ptt {int dummy; } ;
struct qed_hwfn {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DWORDS_TO_BYTES (size_t) ; 
 size_t qed_rd (struct qed_hwfn*,struct qed_ptt*,int /*<<< orphan*/ ) ; 

void qed_read_regs(struct qed_hwfn *p_hwfn,
		   struct qed_ptt *p_ptt, u32 *buf, u32 addr, u32 len)
{
	u32 i;

	for (i = 0; i < len; i++)
		buf[i] = qed_rd(p_hwfn, p_ptt, DWORDS_TO_BYTES(addr + i));
}