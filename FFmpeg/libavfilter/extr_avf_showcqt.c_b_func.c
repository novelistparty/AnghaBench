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
 double av_clipd (double,double,double) ; 
 double lrint (double) ; 

__attribute__((used)) static double b_func(void *p, double x)
{
    x = av_clipd(x, 0.0, 1.0);
    return lrint(x*255.0);
}