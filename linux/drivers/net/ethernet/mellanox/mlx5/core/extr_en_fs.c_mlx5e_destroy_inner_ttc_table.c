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
struct mlx5e_ttc_table {int /*<<< orphan*/  ft; } ;
struct mlx5e_priv {int /*<<< orphan*/  mdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5e_cleanup_ttc_rules (struct mlx5e_ttc_table*) ; 
 int /*<<< orphan*/  mlx5e_destroy_flow_table (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlx5e_tunnel_inner_ft_supported (int /*<<< orphan*/ ) ; 

void mlx5e_destroy_inner_ttc_table(struct mlx5e_priv *priv,
				   struct mlx5e_ttc_table *ttc)
{
	if (!mlx5e_tunnel_inner_ft_supported(priv->mdev))
		return;

	mlx5e_cleanup_ttc_rules(ttc);
	mlx5e_destroy_flow_table(&ttc->ft);
}