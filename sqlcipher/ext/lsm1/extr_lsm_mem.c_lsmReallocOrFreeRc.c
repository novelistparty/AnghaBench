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
typedef  int /*<<< orphan*/  lsm_env ;

/* Variables and functions */
 int LSM_NOMEM_BKPT ; 
 int /*<<< orphan*/  lsmFree (int /*<<< orphan*/ *,void*) ; 
 void* lsmReallocOrFree (int /*<<< orphan*/ *,void*,size_t) ; 

void *lsmReallocOrFreeRc(lsm_env *pEnv, void *p, size_t N, int *pRc){
  void *pRet = 0;
  if( *pRc ){
    lsmFree(pEnv, p);
  }else{
    pRet = lsmReallocOrFree(pEnv, p, N);
    if( !pRet ) *pRc = LSM_NOMEM_BKPT;
  }
  return pRet;
}