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
typedef  int /*<<< orphan*/  u32 ;
struct amd64_pvt {int /*<<< orphan*/  F2; } ;

/* Variables and functions */
 int EINVAL ; 
 int __amd64_read_pci_cfg_dword (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static int k8_read_dct_pci_cfg(struct amd64_pvt *pvt, int addr, u32 *val,
			       const char *func)
{
	if (addr >= 0x100)
		return -EINVAL;

	return __amd64_read_pci_cfg_dword(pvt->F2, addr, val, func);
}