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
typedef  int /*<<< orphan*/  sem_t ;

/* Variables and functions */
 int _libc_sem_init_compat (int /*<<< orphan*/ *,int,unsigned int) ; 

int
_sem_init_compat(sem_t *sem, int pshared, unsigned int value)
{
	return _libc_sem_init_compat(sem, pshared, value);
}