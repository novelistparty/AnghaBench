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
struct TYPE_4__ {int cLlen; struct TYPE_4__** cL; } ;
typedef  TYPE_1__ yyyGNT ;

/* Variables and functions */
 int /*<<< orphan*/  yyyUnsolvedInstSearchTravAux (TYPE_1__*) ; 

void yyyUnsolvedInstSearchTrav(yyyGNT *pNode)
  {yyyGNT **yyyCLpdum;
   int i;
  
   yyyCLpdum = pNode->cL;
   i = pNode->cLlen;
   while (i--)
     {
      yyyUnsolvedInstSearchTravAux(*yyyCLpdum);
      yyyCLpdum++;
     }
  }