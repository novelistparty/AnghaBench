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
struct powerdomain {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  PWRDM_STATE_NOW ; 
 int _pwrdm_state_switch (struct powerdomain*,int /*<<< orphan*/ ) ; 

int pwrdm_state_switch(struct powerdomain *pwrdm)
{
	return _pwrdm_state_switch(pwrdm, PWRDM_STATE_NOW);
}