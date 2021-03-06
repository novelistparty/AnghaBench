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
struct nfc_hci_dev {int dummy; } ;
struct nfc_dev {int dummy; } ;

/* Variables and functions */
 struct nfc_hci_dev* nfc_get_drvdata (struct nfc_dev*) ; 
 int nfc_hci_disconnect_all_gates (struct nfc_hci_dev*) ; 

__attribute__((used)) static int st21nfca_hci_clear_all_pipes(struct nfc_dev *dev, void *data,
				      size_t data_len)
{
	struct nfc_hci_dev *hdev = nfc_get_drvdata(dev);

	return nfc_hci_disconnect_all_gates(hdev);
}