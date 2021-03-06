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
struct controller {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_STATUS ; 
 int shpc_readw (struct controller*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int is_ctrl_busy(struct controller *ctrl)
{
	u16 cmd_status = shpc_readw(ctrl, CMD_STATUS);
	return cmd_status & 0x1;
}