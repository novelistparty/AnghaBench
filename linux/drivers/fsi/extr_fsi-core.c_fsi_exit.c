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

/* Variables and functions */
 int /*<<< orphan*/  FSI_CHAR_MAX_DEVICES ; 
 int /*<<< orphan*/  bus_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fsi_base_dev ; 
 int /*<<< orphan*/  fsi_bus_type ; 
 int /*<<< orphan*/  fsi_minor_ida ; 
 int /*<<< orphan*/  ida_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unregister_chrdev_region (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void fsi_exit(void)
{
	bus_unregister(&fsi_bus_type);
	unregister_chrdev_region(fsi_base_dev, FSI_CHAR_MAX_DEVICES);
	ida_destroy(&fsi_minor_ida);
}