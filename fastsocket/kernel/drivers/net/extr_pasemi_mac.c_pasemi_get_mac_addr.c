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
typedef  int /*<<< orphan*/  const u8 ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct pasemi_mac {int /*<<< orphan*/  mac_addr; struct pci_dev* pdev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  const* of_get_property (struct device_node*,char*,int*) ; 
 struct device_node* pci_device_to_OF_node (struct pci_dev*) ; 
 int sscanf (int /*<<< orphan*/  const*,char*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 

__attribute__((used)) static int pasemi_get_mac_addr(struct pasemi_mac *mac)
{
	struct pci_dev *pdev = mac->pdev;
	struct device_node *dn = pci_device_to_OF_node(pdev);
	int len;
	const u8 *maddr;
	u8 addr[6];

	if (!dn) {
		dev_dbg(&pdev->dev,
			  "No device node for mac, not configuring\n");
		return -ENOENT;
	}

	maddr = of_get_property(dn, "local-mac-address", &len);

	if (maddr && len == 6) {
		memcpy(mac->mac_addr, maddr, 6);
		return 0;
	}

	/* Some old versions of firmware mistakenly uses mac-address
	 * (and as a string) instead of a byte array in local-mac-address.
	 */

	if (maddr == NULL)
		maddr = of_get_property(dn, "mac-address", NULL);

	if (maddr == NULL) {
		dev_warn(&pdev->dev,
			 "no mac address in device tree, not configuring\n");
		return -ENOENT;
	}

	if (sscanf(maddr, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &addr[0],
		   &addr[1], &addr[2], &addr[3], &addr[4], &addr[5]) != 6) {
		dev_warn(&pdev->dev,
			 "can't parse mac address, not configuring\n");
		return -EINVAL;
	}

	memcpy(mac->mac_addr, addr, 6);

	return 0;
}