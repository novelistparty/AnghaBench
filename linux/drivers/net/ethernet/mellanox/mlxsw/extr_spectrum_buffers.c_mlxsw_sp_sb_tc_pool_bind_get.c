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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct mlxsw_sp_sb_cm {int /*<<< orphan*/  pool_index; int /*<<< orphan*/  max_buff; } ;
struct mlxsw_sp_port {int /*<<< orphan*/  local_port; struct mlxsw_sp* mlxsw_sp; } ;
struct mlxsw_sp {int dummy; } ;
struct mlxsw_core_port {int dummy; } ;
typedef  enum mlxsw_reg_sbxx_dir { ____Placeholder_mlxsw_reg_sbxx_dir } mlxsw_reg_sbxx_dir ;
typedef  enum devlink_sb_pool_type { ____Placeholder_devlink_sb_pool_type } devlink_sb_pool_type ;

/* Variables and functions */
 struct mlxsw_sp_port* mlxsw_core_port_driver_priv (struct mlxsw_core_port*) ; 
 struct mlxsw_sp_sb_cm* mlxsw_sp_sb_cm_get (struct mlxsw_sp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlxsw_sp_sb_threshold_out (struct mlxsw_sp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mlxsw_sp_sb_tc_pool_bind_get(struct mlxsw_core_port *mlxsw_core_port,
				 unsigned int sb_index, u16 tc_index,
				 enum devlink_sb_pool_type pool_type,
				 u16 *p_pool_index, u32 *p_threshold)
{
	struct mlxsw_sp_port *mlxsw_sp_port =
			mlxsw_core_port_driver_priv(mlxsw_core_port);
	struct mlxsw_sp *mlxsw_sp = mlxsw_sp_port->mlxsw_sp;
	u8 local_port = mlxsw_sp_port->local_port;
	u8 pg_buff = tc_index;
	enum mlxsw_reg_sbxx_dir dir = (enum mlxsw_reg_sbxx_dir) pool_type;
	struct mlxsw_sp_sb_cm *cm = mlxsw_sp_sb_cm_get(mlxsw_sp, local_port,
						       pg_buff, dir);

	*p_threshold = mlxsw_sp_sb_threshold_out(mlxsw_sp, cm->pool_index,
						 cm->max_buff);
	*p_pool_index = cm->pool_index;
	return 0;
}