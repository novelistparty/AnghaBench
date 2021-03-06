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
struct irq_host {struct device_node* of_node; } ;
struct device_node {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int default_irq_host_match(struct irq_host *h, struct device_node *np)
{
	return h->of_node != NULL && h->of_node == np;
}