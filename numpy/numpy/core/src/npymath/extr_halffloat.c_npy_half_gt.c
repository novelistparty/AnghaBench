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
typedef  int /*<<< orphan*/  npy_half ;

/* Variables and functions */
 int npy_half_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int npy_half_gt(npy_half h1, npy_half h2)
{
    return npy_half_lt(h2, h1);
}