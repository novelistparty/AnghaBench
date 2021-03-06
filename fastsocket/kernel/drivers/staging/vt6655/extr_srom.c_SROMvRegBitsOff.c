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
typedef  int /*<<< orphan*/  DWORD_PTR ;
typedef  int BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  SROMbWriteEmbedded (int /*<<< orphan*/ ,int,int) ; 
 int SROMbyReadEmbedded (int /*<<< orphan*/ ,int) ; 

void SROMvRegBitsOff (DWORD_PTR dwIoBase, BYTE byContntOffset, BYTE byBits)
{
    BYTE    byOrgData;

    byOrgData = SROMbyReadEmbedded(dwIoBase, byContntOffset);
    SROMbWriteEmbedded(dwIoBase, byContntOffset,(BYTE)(byOrgData & (~byBits)));
}