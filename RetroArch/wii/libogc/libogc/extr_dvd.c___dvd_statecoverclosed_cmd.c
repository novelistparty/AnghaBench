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
typedef  int /*<<< orphan*/  dvdcmdblk ;

/* Variables and functions */
 int /*<<< orphan*/  DVD_LowReadId (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __dvd_statecoverclosedcb ; 
 int /*<<< orphan*/  __dvd_tmpid0 ; 

void __dvd_statecoverclosed_cmd(dvdcmdblk *block)
{
	DVD_LowReadId(&__dvd_tmpid0,__dvd_statecoverclosedcb);
}