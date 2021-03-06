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
typedef  int /*<<< orphan*/  UINT32 ;
typedef  int UINT16 ;

/* Variables and functions */
 size_t Rn ; 
 char** regname ; 
 int /*<<< orphan*/  sprintf (char*,char*,int,char*) ; 

__attribute__((used)) static UINT32 op0111(char *buffer, UINT32 pc, UINT16 opcode)
{
	sprintf(buffer, "ADD     #$%02X,%s", opcode & 0xff, regname[Rn]);
	return 0;
}