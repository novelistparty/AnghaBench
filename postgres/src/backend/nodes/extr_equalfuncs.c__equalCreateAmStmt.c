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
typedef  int /*<<< orphan*/  CreateAmStmt ;

/* Variables and functions */
 int /*<<< orphan*/  COMPARE_NODE_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_SCALAR_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  COMPARE_STRING_FIELD (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  amname ; 
 int /*<<< orphan*/  amtype ; 
 int /*<<< orphan*/  handler_name ; 

__attribute__((used)) static bool
_equalCreateAmStmt(const CreateAmStmt *a, const CreateAmStmt *b)
{
	COMPARE_STRING_FIELD(amname);
	COMPARE_NODE_FIELD(handler_name);
	COMPARE_SCALAR_FIELD(amtype);

	return true;
}