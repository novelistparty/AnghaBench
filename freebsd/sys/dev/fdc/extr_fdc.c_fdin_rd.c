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
typedef  int /*<<< orphan*/  u_int8_t ;
struct fdc_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  FDCTL ; 
 int /*<<< orphan*/  fdregrd (struct fdc_data*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u_int8_t
fdin_rd(struct fdc_data *fdc)
{

	return fdregrd(fdc, FDCTL);
}