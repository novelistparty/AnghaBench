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
struct TYPE_3__ {int /*<<< orphan*/  spaces; } ;
typedef  TYPE_1__ RFlag ;

/* Variables and functions */
 int r_spaces_count (int /*<<< orphan*/ *,char const*) ; 

__attribute__((used)) static inline int r_flag_space_count(RFlag *f, const char *name) {
	return r_spaces_count (&f->spaces, name);
}