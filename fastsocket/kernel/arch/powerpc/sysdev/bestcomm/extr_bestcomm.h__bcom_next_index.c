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
struct bcom_task {scalar_t__ index; scalar_t__ num_bd; } ;

/* Variables and functions */

__attribute__((used)) static inline int
_bcom_next_index(struct bcom_task *tsk)
{
	return ((tsk->index + 1) == tsk->num_bd) ? 0 : tsk->index + 1;
}