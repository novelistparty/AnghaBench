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
struct TYPE_3__ {int /*<<< orphan*/  dp; } ;
typedef  int /*<<< orphan*/  STRINGINFO ;
typedef  int /*<<< orphan*/  FICL_WORD ;
typedef  TYPE_1__ FICL_SYSTEM ;

/* Variables and functions */
 int /*<<< orphan*/  SI_PSZ (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * dictLookup (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

FICL_WORD *ficlLookup(FICL_SYSTEM *pSys, char *name)
{
    STRINGINFO si;
    SI_PSZ(si, name);
    return dictLookup(pSys->dp, si);
}