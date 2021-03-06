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
typedef  int u32 ;
struct vpfe_ccdc_black_compensation {int b; int gb; int gr; int r; } ;
struct vpfe_ccdc {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  VPFE_BLKCMP ; 
 int VPFE_BLK_COMP_GB_COMP_SHIFT ; 
 int VPFE_BLK_COMP_GR_COMP_SHIFT ; 
 int VPFE_BLK_COMP_MASK ; 
 int VPFE_BLK_COMP_R_COMP_SHIFT ; 
 int /*<<< orphan*/  vpfe_reg_write (struct vpfe_ccdc*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
vpfe_ccdc_config_black_compense(struct vpfe_ccdc *ccdc,
				struct vpfe_ccdc_black_compensation *bcomp)
{
	u32 val;

	val = ((bcomp->b & VPFE_BLK_COMP_MASK) |
	      ((bcomp->gb & VPFE_BLK_COMP_MASK) <<
	       VPFE_BLK_COMP_GB_COMP_SHIFT) |
	      ((bcomp->gr & VPFE_BLK_COMP_MASK) <<
	       VPFE_BLK_COMP_GR_COMP_SHIFT) |
	      ((bcomp->r & VPFE_BLK_COMP_MASK) <<
	       VPFE_BLK_COMP_R_COMP_SHIFT));
	vpfe_reg_write(ccdc, val, VPFE_BLKCMP);
}