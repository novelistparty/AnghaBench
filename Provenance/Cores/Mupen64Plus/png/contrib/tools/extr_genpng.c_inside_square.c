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
struct arg {int width; } ;

/* Variables and functions */
 scalar_t__ square_check_line (struct arg const*,double,double,int) ; 

__attribute__((used)) static int
inside_square(const struct arg *arg, double x, double y)
{
   /* Return true if within the drawn lines, else false, no need to distinguish
    * INSIDE vs OUTSIDE here:
    */
   return square_check_line(arg, x, y, arg->width/2) == 0;
}