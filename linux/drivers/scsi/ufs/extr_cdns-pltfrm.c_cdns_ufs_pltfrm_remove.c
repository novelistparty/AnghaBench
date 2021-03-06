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
struct ufs_hba {int dummy; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 struct ufs_hba* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  ufshcd_remove (struct ufs_hba*) ; 

__attribute__((used)) static int cdns_ufs_pltfrm_remove(struct platform_device *pdev)
{
	struct ufs_hba *hba =  platform_get_drvdata(pdev);

	ufshcd_remove(hba);
	return 0;
}