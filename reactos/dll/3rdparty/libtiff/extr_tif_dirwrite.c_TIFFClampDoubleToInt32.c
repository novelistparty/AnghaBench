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
typedef  int int32 ;

/* Variables and functions */

__attribute__((used)) static int32 TIFFClampDoubleToInt32( double val )
{
    if( val > 0x7FFFFFFF )
        return 0x7FFFFFFF;
    if( val < -0x7FFFFFFF-1 || val != val )
        return -0x7FFFFFFF-1;
    return (int32)val;
}