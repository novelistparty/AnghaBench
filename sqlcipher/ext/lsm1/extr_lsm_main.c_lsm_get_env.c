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
typedef  int /*<<< orphan*/  lsm_env ;
struct TYPE_3__ {int /*<<< orphan*/ * pEnv; } ;
typedef  TYPE_1__ lsm_db ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 

lsm_env *lsm_get_env(lsm_db *pDb){
  assert( pDb->pEnv );
  return pDb->pEnv;
}