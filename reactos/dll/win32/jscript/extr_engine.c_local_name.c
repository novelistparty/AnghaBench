#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_2__* function; } ;
typedef  TYPE_3__ call_frame_t ;
struct TYPE_6__ {TYPE_1__* variables; int /*<<< orphan*/ * params; } ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  BSTR ;

/* Variables and functions */

__attribute__((used)) static inline BSTR local_name(call_frame_t *frame, int ref)
{
    return ref < 0 ? frame->function->params[-ref-1] : frame->function->variables[ref].name;
}