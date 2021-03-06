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
typedef  int /*<<< orphan*/  VOID ;
typedef  scalar_t__ UINTN ;

/* Variables and functions */

__attribute__((used)) static VOID cursor_left(UINTN *cursor, UINTN *first) {
        if ((*cursor) > 0)
                (*cursor)--;
        else if ((*first) > 0)
                (*first)--;
}