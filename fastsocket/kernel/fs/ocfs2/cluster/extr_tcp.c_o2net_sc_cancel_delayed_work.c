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
struct o2net_sock_container {int dummy; } ;
struct delayed_work {int dummy; } ;

/* Variables and functions */
 scalar_t__ cancel_delayed_work (struct delayed_work*) ; 
 int /*<<< orphan*/  sc_put (struct o2net_sock_container*) ; 

__attribute__((used)) static void o2net_sc_cancel_delayed_work(struct o2net_sock_container *sc,
					 struct delayed_work *work)
{
	if (cancel_delayed_work(work))
		sc_put(sc);
}