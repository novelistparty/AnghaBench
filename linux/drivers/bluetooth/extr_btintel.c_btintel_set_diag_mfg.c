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
struct hci_dev {int dummy; } ;

/* Variables and functions */
 int btintel_enter_mfg (struct hci_dev*) ; 
 int btintel_exit_mfg (struct hci_dev*,int,int) ; 
 int btintel_set_diag (struct hci_dev*,int) ; 

int btintel_set_diag_mfg(struct hci_dev *hdev, bool enable)
{
	int err, ret;

	err = btintel_enter_mfg(hdev);
	if (err)
		return err;

	ret = btintel_set_diag(hdev, enable);

	err = btintel_exit_mfg(hdev, false, false);
	if (err)
		return err;

	return ret;
}