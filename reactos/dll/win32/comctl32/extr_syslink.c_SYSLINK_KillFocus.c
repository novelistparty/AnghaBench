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
struct TYPE_5__ {int /*<<< orphan*/  HasFocus; } ;
typedef  TYPE_1__ SYSLINK_INFO ;
typedef  int /*<<< orphan*/ * PDOC_ITEM ;
typedef  int /*<<< orphan*/  LRESULT ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * SYSLINK_GetFocusLink (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SYSLINK_RepaintLink (TYPE_1__*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static LRESULT SYSLINK_KillFocus (SYSLINK_INFO *infoPtr)
{
    PDOC_ITEM Focus;
    
    infoPtr->HasFocus = FALSE;
    Focus = SYSLINK_GetFocusLink(infoPtr, NULL);
    
    if(Focus != NULL)
    {
        SYSLINK_RepaintLink(infoPtr, Focus);
    }

    return 0;
}