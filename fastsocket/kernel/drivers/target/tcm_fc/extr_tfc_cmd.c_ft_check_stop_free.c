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
struct se_cmd {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  transport_generic_free_cmd (struct se_cmd*,int /*<<< orphan*/ ) ; 

int ft_check_stop_free(struct se_cmd *se_cmd)
{
	transport_generic_free_cmd(se_cmd, 0);
	return 1;
}