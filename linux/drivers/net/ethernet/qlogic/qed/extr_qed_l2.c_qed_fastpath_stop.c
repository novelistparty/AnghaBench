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
struct qed_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DP_ERR (struct qed_dev*,char*) ; 
 int qed_hw_stop_fastpath (struct qed_dev*) ; 

__attribute__((used)) static int qed_fastpath_stop(struct qed_dev *cdev)
{
	int rc;

	rc = qed_hw_stop_fastpath(cdev);
	if (rc) {
		DP_ERR(cdev, "Failed to stop Fastpath\n");
		return rc;
	}

	return 0;
}