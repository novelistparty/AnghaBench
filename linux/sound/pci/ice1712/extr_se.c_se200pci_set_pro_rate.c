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
struct snd_ice1712 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  se200pci_WM8740_set_pro_rate (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  se200pci_WM8766_set_pro_rate (struct snd_ice1712*,unsigned int) ; 
 int /*<<< orphan*/  se200pci_WM8776_set_pro_rate (struct snd_ice1712*,unsigned int) ; 

__attribute__((used)) static void se200pci_set_pro_rate(struct snd_ice1712 *ice, unsigned int rate)
{
	se200pci_WM8740_set_pro_rate(ice, rate);
	se200pci_WM8766_set_pro_rate(ice, rate);
	se200pci_WM8776_set_pro_rate(ice, rate);
}