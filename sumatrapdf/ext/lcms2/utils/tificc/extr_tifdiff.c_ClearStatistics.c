#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int Min; scalar_t__ Peak; scalar_t__ x2; scalar_t__ x; scalar_t__ n; } ;
typedef  TYPE_1__* LPSTAT ;

/* Variables and functions */

__attribute__((used)) static
void ClearStatistics(LPSTAT st)
{

    st ->n = st ->x = st->x2 = st->Peak = 0;
    st ->Min = 1E10;

}