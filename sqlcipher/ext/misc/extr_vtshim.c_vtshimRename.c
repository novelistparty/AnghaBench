#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  pChild; TYPE_3__* pAux; } ;
typedef  TYPE_2__ vtshim_vtab ;
struct TYPE_6__ {TYPE_1__* pMod; scalar_t__ bDisposed; } ;
typedef  TYPE_3__ vtshim_aux ;
typedef  int /*<<< orphan*/  sqlite3_vtab ;
struct TYPE_4__ {int (* xRename ) (int /*<<< orphan*/ ,char const*) ;} ;

/* Variables and functions */
 int SQLITE_ERROR ; 
 int SQLITE_OK ; 
 int /*<<< orphan*/  VTSHIM_COPY_ERRMSG () ; 
 int stub1 (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static int vtshimRename(sqlite3_vtab *pBase, const char *zNewName){
  vtshim_vtab *pVtab = (vtshim_vtab*)pBase;
  vtshim_aux *pAux = pVtab->pAux;
  int rc;
  if( pAux->bDisposed ) return SQLITE_ERROR;
  rc = pAux->pMod->xRename(pVtab->pChild, zNewName);
  if( rc!=SQLITE_OK ){
    VTSHIM_COPY_ERRMSG();
  }
  return rc;
}