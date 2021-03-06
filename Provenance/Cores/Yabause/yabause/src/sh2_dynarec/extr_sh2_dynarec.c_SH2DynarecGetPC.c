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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  SH2_struct ;

/* Variables and functions */
 int /*<<< orphan*/ * MSH2 ; 
 int /*<<< orphan*/  master_pc ; 
 int /*<<< orphan*/  slave_pc ; 

u32 SH2DynarecGetPC(SH2_struct *context)
{
  if(context==MSH2) 
    return master_pc;
  else
    return slave_pc;
}