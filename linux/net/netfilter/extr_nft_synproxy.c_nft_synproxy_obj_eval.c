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
struct nft_synproxy {int dummy; } ;
struct nft_regs {int dummy; } ;
struct nft_pktinfo {int dummy; } ;
struct nft_object {int dummy; } ;

/* Variables and functions */
 struct nft_synproxy* nft_obj_data (struct nft_object*) ; 
 int /*<<< orphan*/  nft_synproxy_do_eval (struct nft_synproxy const*,struct nft_regs*,struct nft_pktinfo const*) ; 

__attribute__((used)) static void nft_synproxy_obj_eval(struct nft_object *obj,
				  struct nft_regs *regs,
				  const struct nft_pktinfo *pkt)
{
	const struct nft_synproxy *priv = nft_obj_data(obj);

	nft_synproxy_do_eval(priv, regs, pkt);
}