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
struct athregrec {int reg; int val; } ;

/* Variables and functions */
 int /*<<< orphan*/  printf (char*,int,int) ; 

__attribute__((used)) static void
op_write(struct athregrec *a)
{
        printf("write\t%.8x = %.8x\n", a->reg, a->val);
}