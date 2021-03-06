#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  end; int /*<<< orphan*/  start; int /*<<< orphan*/  buf; } ;
typedef  TYPE_1__ RangeObject ;
typedef  int /*<<< orphan*/  PyObject ;

/* Variables and functions */
 int /*<<< orphan*/ * RBAppend (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static PyObject *
RangeAppend(RangeObject *self, PyObject *args)
{
    return RBAppend(self->buf, args, self->start, self->end, &self->end);
}