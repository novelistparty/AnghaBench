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
struct TYPE_4__ {scalar_t__ name; } ;
typedef  TYPE_1__ RAnalFunction ;

/* Variables and functions */
 scalar_t__ strlen (scalar_t__) ; 

__attribute__((used)) static int compareNameLen(const RAnalFunction *a, const RAnalFunction *b) {
	return a && b && a->name && b->name && strlen (a->name) > strlen (b->name);
}