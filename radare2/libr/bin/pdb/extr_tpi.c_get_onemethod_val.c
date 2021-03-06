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
struct TYPE_4__ {int val; } ;
struct TYPE_6__ {TYPE_1__ val; } ;
struct TYPE_5__ {scalar_t__ type_info; } ;
typedef  TYPE_2__ STypeInfo ;
typedef  TYPE_3__ SLF_ONEMETHOD ;

/* Variables and functions */

__attribute__((used)) static void get_onemethod_val(void *type, int *res) {
	STypeInfo *t = (STypeInfo *) type;
	SLF_ONEMETHOD *lf = (SLF_ONEMETHOD *) t->type_info;

	*res = lf->val.val;
}