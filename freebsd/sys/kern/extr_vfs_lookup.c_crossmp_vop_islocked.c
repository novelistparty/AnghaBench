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
struct vop_islocked_args {int dummy; } ;

/* Variables and functions */
 int LK_SHARED ; 

__attribute__((used)) static int
crossmp_vop_islocked(struct vop_islocked_args *ap)
{

	return (LK_SHARED);
}