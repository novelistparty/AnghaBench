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
struct sock {int dummy; } ;
struct cn_queue_dev {int /*<<< orphan*/  wq_creation; struct sock* nls; int /*<<< orphan*/  wq_created; int /*<<< orphan*/  queue_lock; int /*<<< orphan*/  queue_list; int /*<<< orphan*/  refcnt; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  INIT_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cn_queue_create ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 struct cn_queue_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 

struct cn_queue_dev *cn_queue_alloc_dev(char *name, struct sock *nls)
{
	struct cn_queue_dev *dev;

	dev = kzalloc(sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return NULL;

	snprintf(dev->name, sizeof(dev->name), "%s", name);
	atomic_set(&dev->refcnt, 0);
	INIT_LIST_HEAD(&dev->queue_list);
	spin_lock_init(&dev->queue_lock);
	init_waitqueue_head(&dev->wq_created);

	dev->nls = nls;

	INIT_WORK(&dev->wq_creation, cn_queue_create);

	return dev;
}