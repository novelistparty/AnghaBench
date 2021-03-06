#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct pci_dev {TYPE_1__* bus; } ;
struct ath_softc {int /*<<< orphan*/  dev; struct ath_hw* sc_ah; } ;
struct ath_hw {int aspm_enabled; int /*<<< orphan*/  is_pciexpress; } ;
struct ath_common {scalar_t__ priv; } ;
struct TYPE_2__ {struct pci_dev* self; } ;

/* Variables and functions */
 scalar_t__ AR_SREV_9285 (struct ath_hw*) ; 
 scalar_t__ ATH_BTCOEX_CFG_NONE ; 
 int /*<<< orphan*/  PCI_EXP_LNKCTL ; 
 int PCI_EXP_LNKCTL_ASPM_L0S ; 
 int PCI_EXP_LNKCTL_ASPM_L1 ; 
 int /*<<< orphan*/  ath9k_hw_configpcipowersave (struct ath_hw*,int) ; 
 scalar_t__ ath9k_hw_get_btcoex_scheme (struct ath_hw*) ; 
 int /*<<< orphan*/  ath_info (struct ath_common*,char*,...) ; 
 int /*<<< orphan*/  pcie_capability_clear_word (struct pci_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pcie_capability_read_word (struct pci_dev*,int /*<<< orphan*/ ,int*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ath_pci_aspm_init(struct ath_common *common)
{
	struct ath_softc *sc = (struct ath_softc *) common->priv;
	struct ath_hw *ah = sc->sc_ah;
	struct pci_dev *pdev = to_pci_dev(sc->dev);
	struct pci_dev *parent;
	u16 aspm;

	if (!ah->is_pciexpress)
		return;

	parent = pdev->bus->self;
	if (!parent)
		return;

	if ((ath9k_hw_get_btcoex_scheme(ah) != ATH_BTCOEX_CFG_NONE) &&
	    (AR_SREV_9285(ah))) {
		/* Bluetooth coexistence requires disabling ASPM. */
		pcie_capability_clear_word(pdev, PCI_EXP_LNKCTL,
			PCI_EXP_LNKCTL_ASPM_L0S | PCI_EXP_LNKCTL_ASPM_L1);

		/*
		 * Both upstream and downstream PCIe components should
		 * have the same ASPM settings.
		 */
		pcie_capability_clear_word(parent, PCI_EXP_LNKCTL,
			PCI_EXP_LNKCTL_ASPM_L0S | PCI_EXP_LNKCTL_ASPM_L1);

		ath_info(common, "Disabling ASPM since BTCOEX is enabled\n");
		return;
	}

	pcie_capability_read_word(parent, PCI_EXP_LNKCTL, &aspm);
	if (aspm & (PCI_EXP_LNKCTL_ASPM_L0S | PCI_EXP_LNKCTL_ASPM_L1)) {
		ah->aspm_enabled = true;
		/* Initialize PCIe PM and SERDES registers. */
		ath9k_hw_configpcipowersave(ah, false);
		ath_info(common, "ASPM enabled: 0x%x\n", aspm);
	}
}