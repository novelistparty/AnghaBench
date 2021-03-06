#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ incomplete_elems; } ;
typedef  TYPE_1__ Type ;

/* Variables and functions */
 scalar_t__ is_array_type (TYPE_1__*) ; 

bool is_incomplete_array_type(Type *type) {
    return type && is_array_type(type) && type->incomplete_elems;
}