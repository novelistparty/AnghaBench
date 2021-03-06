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
struct virtnet_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  _free_receive_bufs (struct virtnet_info*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 

__attribute__((used)) static void free_receive_bufs(struct virtnet_info *vi)
{
	rtnl_lock();
	_free_receive_bufs(vi);
	rtnl_unlock();
}