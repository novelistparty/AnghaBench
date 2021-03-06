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
struct TYPE_4__ {int /*<<< orphan*/  Data; } ;
typedef  TYPE_1__ TCP_RAW_DATA ;

/* Variables and functions */
 int /*<<< orphan*/  Free (TYPE_1__*) ; 
 int /*<<< orphan*/  ReleaseFifo (int /*<<< orphan*/ ) ; 

void FreeTcpRawData(TCP_RAW_DATA *trd)
{
	// Validate arguments
	if (trd == NULL)
	{
		return;
	}

	ReleaseFifo(trd->Data);
	Free(trd);
}