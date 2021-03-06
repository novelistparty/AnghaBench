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
typedef  int u8 ;
struct ata_port {scalar_t__ private_data; } ;

/* Variables and functions */
 int GAYLE_IRQ_IDE ; 
 int z_readb (unsigned long) ; 

__attribute__((used)) static bool pata_gayle_irq_check(struct ata_port *ap)
{
	u8 ch;

	ch = z_readb((unsigned long)ap->private_data);

	return !!(ch & GAYLE_IRQ_IDE);
}