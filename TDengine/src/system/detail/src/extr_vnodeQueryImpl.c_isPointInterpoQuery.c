#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t int32_t ;
struct TYPE_7__ {size_t numOfOutputCols; TYPE_2__* pSelectExpr; } ;
struct TYPE_5__ {size_t functionId; } ;
struct TYPE_6__ {TYPE_1__ pBase; } ;
typedef  TYPE_3__ SQuery ;

/* Variables and functions */
 size_t TSDB_FUNC_INTERP ; 
 size_t TSDB_FUNC_LAST_ROW ; 

bool isPointInterpoQuery(SQuery *pQuery) {
  for (int32_t i = 0; i < pQuery->numOfOutputCols; ++i) {
    int32_t functionID = pQuery->pSelectExpr[i].pBase.functionId;
    if (functionID == TSDB_FUNC_INTERP || functionID == TSDB_FUNC_LAST_ROW) {
      return true;
    }
  }

  return false;
}