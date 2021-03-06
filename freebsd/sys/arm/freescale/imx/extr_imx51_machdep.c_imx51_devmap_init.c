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
typedef  int /*<<< orphan*/  platform_t ;

/* Variables and functions */
 int /*<<< orphan*/  devmap_add_entry (int,int) ; 

__attribute__((used)) static int
imx51_devmap_init(platform_t plat)
{

	devmap_add_entry(0x70000000, 0x00100000);
	devmap_add_entry(0x73f00000, 0x00100000);
	devmap_add_entry(0x83f00000, 0x00100000);

	return (0);
}