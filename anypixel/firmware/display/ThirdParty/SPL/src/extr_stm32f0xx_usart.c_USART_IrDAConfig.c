#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct TYPE_4__ {scalar_t__ CR3; } ;
typedef  TYPE_1__ USART_TypeDef ;

/* Variables and functions */
 int /*<<< orphan*/  IS_USART_12_PERIPH (TYPE_1__*) ; 
 int /*<<< orphan*/  IS_USART_IRDA_MODE (scalar_t__) ; 
 scalar_t__ USART_CR3_IRLP ; 
 int /*<<< orphan*/  assert_param (int /*<<< orphan*/ ) ; 

void USART_IrDAConfig(USART_TypeDef* USARTx, uint32_t USART_IrDAMode)
{
  /* Check the parameters */
  assert_param(IS_USART_12_PERIPH(USARTx));
  assert_param(IS_USART_IRDA_MODE(USART_IrDAMode));

  USARTx->CR3 &= (uint32_t)~((uint32_t)USART_CR3_IRLP);
  USARTx->CR3 |= USART_IrDAMode;
}