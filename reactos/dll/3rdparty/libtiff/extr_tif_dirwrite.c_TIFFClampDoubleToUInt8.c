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
typedef  int uint8 ;

/* Variables and functions */

__attribute__((used)) static uint8 TIFFClampDoubleToUInt8( double val )
{
    if( val < 0 )
        return 0;
    if( val > 255 || val != val )
        return 255;
    return (uint8)val;
}