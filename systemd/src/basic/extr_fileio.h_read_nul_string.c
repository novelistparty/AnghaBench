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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  READ_LINE_ONLY_NUL ; 
 int read_line_full (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,char**) ; 

__attribute__((used)) static inline int read_nul_string(FILE *f, size_t limit, char **ret) {
        return read_line_full(f, limit, READ_LINE_ONLY_NUL, ret);
}