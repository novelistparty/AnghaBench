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
struct mlx5_core_rsc_common {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5_core_put_rsc (struct mlx5_core_rsc_common*) ; 

void mlx5_core_res_put(struct mlx5_core_rsc_common *res)
{
	mlx5_core_put_rsc(res);
}