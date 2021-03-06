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
typedef  int /*<<< orphan*/  RAnalReilArg ;
typedef  int /*<<< orphan*/  RAnalEsil ;

/* Variables and functions */
 int /*<<< orphan*/  R_FREE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reil_eq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reil_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * reil_pop_arg (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  reil_push_arg (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool reil_inceq(RAnalEsil *esil) {
	RAnalReilArg *op = reil_pop_arg(esil);
	if (!op) {
		return false;
	}
	reil_push_arg (esil, op);
	reil_inc (esil);
	reil_push_arg (esil, op);
	reil_eq (esil);
	R_FREE (op);
	return true;
}