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
typedef  int /*<<< orphan*/  u64 ;
struct firedtv {int dummy; } ;
typedef  int /*<<< orphan*/  quadlet_t ;

/* Variables and functions */
 int /*<<< orphan*/  EXTCODE_COMPARE_SWAP ; 
 int hpsb_node_lock (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  node_of (struct firedtv*) ; 

__attribute__((used)) static int node_lock(struct firedtv *fdtv, u64 addr, void *data)
{
	quadlet_t *d = data;
	int ret;

	ret = hpsb_node_lock(node_of(fdtv), addr,
			     EXTCODE_COMPARE_SWAP, &d[1], d[0]);
	d[0] = d[1];

	return ret;
}