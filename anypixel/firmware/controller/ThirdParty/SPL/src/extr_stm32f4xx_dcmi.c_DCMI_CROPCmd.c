#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  CR; } ;
typedef  scalar_t__ FunctionalState ;

/* Variables and functions */
 TYPE_1__* DCMI ; 
 scalar_t__ DCMI_CR_CROP ; 
 scalar_t__ DISABLE ; 
 int /*<<< orphan*/  IS_FUNCTIONAL_STATE (scalar_t__) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void DCMI_CROPCmd(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
    
  if (NewState != DISABLE)
  {
    /* Enable the DCMI Crop feature */
    DCMI->CR |= (uint32_t)DCMI_CR_CROP;
  }
  else
  {
    /* Disable the DCMI Crop feature */
    DCMI->CR &= ~(uint32_t)DCMI_CR_CROP;
  }
}