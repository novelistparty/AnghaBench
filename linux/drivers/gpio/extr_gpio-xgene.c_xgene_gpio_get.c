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
struct xgene_gpio {scalar_t__ base; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 unsigned long GPIO_BANK_OFFSET (unsigned int) ; 
 int /*<<< orphan*/  GPIO_BIT_OFFSET (unsigned int) ; 
 unsigned long GPIO_DATA_OFFSET ; 
 struct xgene_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int ioread32 (scalar_t__) ; 

__attribute__((used)) static int xgene_gpio_get(struct gpio_chip *gc, unsigned int offset)
{
	struct xgene_gpio *chip = gpiochip_get_data(gc);
	unsigned long bank_offset;
	u32 bit_offset;

	bank_offset = GPIO_DATA_OFFSET + GPIO_BANK_OFFSET(offset);
	bit_offset = GPIO_BIT_OFFSET(offset);
	return !!(ioread32(chip->base + bank_offset) & BIT(bit_offset));
}