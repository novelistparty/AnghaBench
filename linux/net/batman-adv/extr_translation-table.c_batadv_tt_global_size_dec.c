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
struct batadv_orig_node {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  batadv_tt_global_size_mod (struct batadv_orig_node*,unsigned short,int) ; 

__attribute__((used)) static void batadv_tt_global_size_dec(struct batadv_orig_node *orig_node,
				      unsigned short vid)
{
	batadv_tt_global_size_mod(orig_node, vid, -1);
}