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
struct timer8_priv {scalar_t__ mapbase; } ;

/* Variables and functions */
 scalar_t__ TCORA ; 
 scalar_t__ _8TCNT ; 
 scalar_t__ _8TCR ; 
 int /*<<< orphan*/  iowrite16be (int,scalar_t__) ; 

__attribute__((used)) static int timer8_enable(struct timer8_priv *p)
{
	iowrite16be(0xffff, p->mapbase + TCORA);
	iowrite16be(0x0000, p->mapbase + _8TCNT);
	iowrite16be(0x0c02, p->mapbase + _8TCR);

	return 0;
}