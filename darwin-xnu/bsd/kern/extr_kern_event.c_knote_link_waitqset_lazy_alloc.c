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
struct kqueue {int /*<<< orphan*/  kq_wqs; } ;
struct knote {int dummy; } ;

/* Variables and functions */
 struct kqueue* knote_get_kq (struct knote*) ; 
 int /*<<< orphan*/  waitq_set_lazy_init_link (int /*<<< orphan*/ *) ; 

void
knote_link_waitqset_lazy_alloc(struct knote *kn)
{
	struct kqueue *kq = knote_get_kq(kn);
	waitq_set_lazy_init_link(&kq->kq_wqs);
}