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
struct vnop_create_args {int dummy; } ;

/* Variables and functions */
 int ENOTSUP ; 
 int /*<<< orphan*/  nop_create (struct vnop_create_args*) ; 

int
err_create(struct vnop_create_args *ap)
{
	(void)nop_create(ap);
	return (ENOTSUP);
}