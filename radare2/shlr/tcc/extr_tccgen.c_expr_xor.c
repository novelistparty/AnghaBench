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

/* Variables and functions */
 int /*<<< orphan*/  expr_and () ; 
 int /*<<< orphan*/  next () ; 
 char tok ; 

__attribute__((used)) static void expr_xor(void) {
	expr_and ();
	while (tok == '^') {
		next ();
		expr_and ();
	}
}