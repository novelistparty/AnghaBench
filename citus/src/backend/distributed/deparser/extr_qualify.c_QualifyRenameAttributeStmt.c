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
struct TYPE_4__ {scalar_t__ renameType; int relationType; } ;
typedef  TYPE_1__ RenameStmt ;

/* Variables and functions */
 int /*<<< orphan*/  Assert (int) ; 
 scalar_t__ OBJECT_ATTRIBUTE ; 
#define  OBJECT_TYPE 128 
 int /*<<< orphan*/  QualifyRenameTypeAttributeStmt (TYPE_1__*) ; 

__attribute__((used)) static void
QualifyRenameAttributeStmt(RenameStmt *stmt)
{
	Assert(stmt->renameType == OBJECT_ATTRIBUTE);

	switch (stmt->relationType)
	{
		case OBJECT_TYPE:
		{
			QualifyRenameTypeAttributeStmt(stmt);
			return;
		}

		default:
		{
			return;
		}
	}
}