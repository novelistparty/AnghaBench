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
struct encx24j600_priv {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ECON2 ; 
 int /*<<< orphan*/  TXRST ; 
 int /*<<< orphan*/  encx24j600_clr_bits (struct encx24j600_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  encx24j600_set_bits (struct encx24j600_priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void encx24j600_reset_hw_tx(struct encx24j600_priv *priv)
{
	encx24j600_set_bits(priv, ECON2, TXRST);
	encx24j600_clr_bits(priv, ECON2, TXRST);
}