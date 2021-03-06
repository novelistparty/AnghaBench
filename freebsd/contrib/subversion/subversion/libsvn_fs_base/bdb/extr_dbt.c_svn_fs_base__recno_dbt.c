#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  db_recno_t ;
struct TYPE_5__ {int /*<<< orphan*/  flags; int /*<<< orphan*/  size; int /*<<< orphan*/  ulen; } ;
typedef  TYPE_1__ DBT ;

/* Variables and functions */
 int /*<<< orphan*/  DB_DBT_USERMEM ; 
 int /*<<< orphan*/  svn_fs_base__set_dbt (TYPE_1__*,int /*<<< orphan*/ *,int) ; 

DBT *
svn_fs_base__recno_dbt(DBT *dbt, db_recno_t *recno)
{
  svn_fs_base__set_dbt(dbt, recno, sizeof(*recno));
  dbt->ulen = dbt->size;
  dbt->flags |= DB_DBT_USERMEM;

  return dbt;
}