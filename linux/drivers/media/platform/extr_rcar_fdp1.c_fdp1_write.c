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
struct fdp1_dev {scalar_t__ regs; } ;

/* Variables and functions */
 int debug ; 
 int /*<<< orphan*/  dprintk (struct fdp1_dev*,char*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  iowrite32 (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static void fdp1_write(struct fdp1_dev *fdp1, u32 val, unsigned int reg)
{
	if (debug >= 2)
		dprintk(fdp1, "Write 0x%08x to 0x%04x\n", val, reg);

	iowrite32(val, fdp1->regs + reg);
}