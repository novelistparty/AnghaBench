#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sqlite3_context ;
struct TYPE_3__ {scalar_t__ cnt; double rSum; } ;
typedef  TYPE_1__ SumCtx ;

/* Variables and functions */
 TYPE_1__* sqlite3_aggregate_context (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sqlite3_result_double (int /*<<< orphan*/ *,double) ; 

__attribute__((used)) static void avgFinalize(sqlite3_context *context){
  SumCtx *p;
  p = sqlite3_aggregate_context(context, 0);
  if( p && p->cnt>0 ){
    sqlite3_result_double(context, p->rSum/(double)p->cnt);
  }
}