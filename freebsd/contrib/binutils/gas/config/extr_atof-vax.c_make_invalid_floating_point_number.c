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
typedef  int LITTLENUM_TYPE ;

/* Variables and functions */

__attribute__((used)) static void
make_invalid_floating_point_number (LITTLENUM_TYPE *words)
{
  *words = 0x8000;		/* Floating Reserved Operand Code.  */
}