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

/* Variables and functions */
 double ceil (double) ; 
 double floor (double) ; 

__attribute__((used)) static inline double rint(double x)
{
    return x >= 0 ? floor(x + 0.5) : ceil(x - 0.5);
}