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
struct TYPE_4__ {int code; struct TYPE_4__* next; } ;
typedef  TYPE_1__ mseRegion ;

/* Variables and functions */
 TYPE_1__* regionList ; 

__attribute__((used)) static mseRegion *
find_region_by_code(int code)
{
    mseRegion *butPtr;

    for (butPtr = regionList; butPtr; butPtr = butPtr->next) {
	if (code == butPtr->code)
	    break;
    }
    return butPtr;
}