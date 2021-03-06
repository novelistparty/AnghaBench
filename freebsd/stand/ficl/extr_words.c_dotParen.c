#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {char* pad; } ;
typedef  TYPE_1__ FICL_VM ;

/* Variables and functions */
 char* vmGetInBuf (TYPE_1__*) ; 
 char* vmGetInBufEnd (TYPE_1__*) ; 
 int /*<<< orphan*/  vmTextOut (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vmUpdateTib (TYPE_1__*,char*) ; 

__attribute__((used)) static void dotParen(FICL_VM *pVM)
{
    char *pSrc      = vmGetInBuf(pVM);
    char *pEnd      = vmGetInBufEnd(pVM);
    char *pDest     = pVM->pad;
    char ch;

    /*
    ** Note: the standard does not want leading spaces skipped (apparently)
    */
    for (ch = *pSrc; (pEnd != pSrc) && (ch != ')'); ch = *++pSrc)
        *pDest++ = ch;

    *pDest = '\0';
    if ((pEnd != pSrc) && (ch == ')'))
        pSrc++;

    vmTextOut(pVM, pVM->pad, 0);
    vmUpdateTib(pVM, pSrc);
        
    return;
}