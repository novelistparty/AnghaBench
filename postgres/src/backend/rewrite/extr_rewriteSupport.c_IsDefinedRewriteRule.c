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
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  ObjectIdGetDatum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PointerGetDatum (char const*) ; 
 int /*<<< orphan*/  RULERELNAME ; 
 int SearchSysCacheExists2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool
IsDefinedRewriteRule(Oid owningRel, const char *ruleName)
{
	return SearchSysCacheExists2(RULERELNAME,
								 ObjectIdGetDatum(owningRel),
								 PointerGetDatum(ruleName));
}