#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_6__ {scalar_t__ SR2; } ;
struct TYPE_5__ {scalar_t__ SR3; } ;
struct TYPE_4__ {scalar_t__ SR4; } ;

/* Variables and functions */
 TYPE_3__* FSMC_Bank2 ; 
 scalar_t__ FSMC_Bank2_NAND ; 
 TYPE_2__* FSMC_Bank3 ; 
 scalar_t__ FSMC_Bank3_NAND ; 
 TYPE_1__* FSMC_Bank4 ; 
 int /*<<< orphan*/  IS_FSMC_IT (scalar_t__) ; 
 int /*<<< orphan*/  IS_FSMC_IT_BANK (scalar_t__) ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT)
{
  /* Check the parameters */
  assert_param(IS_FSMC_IT_BANK(FSMC_Bank));
  assert_param(IS_FSMC_IT(FSMC_IT));
    
  if(FSMC_Bank == FSMC_Bank2_NAND)
  {
    FSMC_Bank2->SR2 &= ~(FSMC_IT >> 3); 
  }  
  else if(FSMC_Bank == FSMC_Bank3_NAND)
  {
    FSMC_Bank3->SR3 &= ~(FSMC_IT >> 3);
  }
  /* FSMC_Bank4_PCCARD*/
  else
  {
    FSMC_Bank4->SR4 &= ~(FSMC_IT >> 3);
  }
}