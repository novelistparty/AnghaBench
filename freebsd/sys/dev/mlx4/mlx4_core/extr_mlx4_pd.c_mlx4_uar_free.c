#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct mlx4_uar {int /*<<< orphan*/  index; } ;
struct mlx4_dev {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  bitmap; } ;
struct TYPE_4__ {TYPE_1__ uar_table; } ;

/* Variables and functions */
 int /*<<< orphan*/  MLX4_USE_RR ; 
 int /*<<< orphan*/  mlx4_bitmap_free (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__* mlx4_priv (struct mlx4_dev*) ; 

void mlx4_uar_free(struct mlx4_dev *dev, struct mlx4_uar *uar)
{
	mlx4_bitmap_free(&mlx4_priv(dev)->uar_table.bitmap, uar->index, MLX4_USE_RR);
}