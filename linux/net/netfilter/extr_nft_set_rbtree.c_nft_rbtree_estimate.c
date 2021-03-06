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
typedef  int /*<<< orphan*/  u32 ;
struct nft_set_estimate {int size; int /*<<< orphan*/  space; int /*<<< orphan*/  lookup; } ;
struct nft_set_desc {int size; } ;
struct nft_rbtree_elem {int dummy; } ;
struct nft_rbtree {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  NFT_SET_CLASS_O_LOG_N ; 
 int /*<<< orphan*/  NFT_SET_CLASS_O_N ; 

__attribute__((used)) static bool nft_rbtree_estimate(const struct nft_set_desc *desc, u32 features,
				struct nft_set_estimate *est)
{
	if (desc->size)
		est->size = sizeof(struct nft_rbtree) +
			    desc->size * sizeof(struct nft_rbtree_elem);
	else
		est->size = ~0;

	est->lookup = NFT_SET_CLASS_O_LOG_N;
	est->space  = NFT_SET_CLASS_O_N;

	return true;
}