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
struct sk_buff {int len; } ;
struct cpl_tx_pkt {int dummy; } ;

/* Variables and functions */
 int MAX_IMM_TX_PKT_LEN ; 

__attribute__((used)) static inline int is_eth_imm(const struct sk_buff *skb)
{
	return skb->len <= MAX_IMM_TX_PKT_LEN - sizeof(struct cpl_tx_pkt);
}