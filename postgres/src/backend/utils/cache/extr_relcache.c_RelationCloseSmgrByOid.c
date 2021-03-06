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
typedef  int /*<<< orphan*/  Relation ;
typedef  int /*<<< orphan*/  Oid ;

/* Variables and functions */
 int /*<<< orphan*/  PointerIsValid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RelationCloseSmgr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RelationIdCacheLookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
RelationCloseSmgrByOid(Oid relationId)
{
	Relation	relation;

	RelationIdCacheLookup(relationId, relation);

	if (!PointerIsValid(relation))
		return;					/* not in cache, nothing to do */

	RelationCloseSmgr(relation);
}