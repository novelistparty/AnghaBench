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
typedef  int u16 ;
struct orion_mdio_dev {scalar_t__ regs; } ;
struct mii_bus {struct orion_mdio_dev* priv; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int GENMASK (int,int /*<<< orphan*/ ) ; 
 int MII_ADDR_C45 ; 
 scalar_t__ MVMDIO_XSMI_ADDR_REG ; 
 int MVMDIO_XSMI_DEVADDR_SHIFT ; 
 scalar_t__ MVMDIO_XSMI_MGNT_REG ; 
 int MVMDIO_XSMI_PHYADDR_SHIFT ; 
 int MVMDIO_XSMI_WRITE_OPERATION ; 
 int orion_mdio_wait_ready (int /*<<< orphan*/ *,struct mii_bus*) ; 
 int /*<<< orphan*/  orion_mdio_xsmi_ops ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static int orion_mdio_xsmi_write(struct mii_bus *bus, int mii_id,
				int regnum, u16 value)
{
	struct orion_mdio_dev *dev = bus->priv;
	u16 dev_addr = (regnum >> 16) & GENMASK(4, 0);
	int ret;

	if (!(regnum & MII_ADDR_C45))
		return -EOPNOTSUPP;

	ret = orion_mdio_wait_ready(&orion_mdio_xsmi_ops, bus);
	if (ret < 0)
		return ret;

	writel(regnum & GENMASK(15, 0), dev->regs + MVMDIO_XSMI_ADDR_REG);
	writel((mii_id << MVMDIO_XSMI_PHYADDR_SHIFT) |
	       (dev_addr << MVMDIO_XSMI_DEVADDR_SHIFT) |
	       MVMDIO_XSMI_WRITE_OPERATION | value,
	       dev->regs + MVMDIO_XSMI_MGNT_REG);

	return 0;
}