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
struct mlxsw_afk_key_info {int /*<<< orphan*/  elusage; } ;
struct mlxsw_afk_element_usage {int dummy; } ;

/* Variables and functions */
 scalar_t__ memcmp (int /*<<< orphan*/ *,struct mlxsw_afk_element_usage*,int) ; 

__attribute__((used)) static bool
mlxsw_afk_key_info_elements_eq(struct mlxsw_afk_key_info *key_info,
			       struct mlxsw_afk_element_usage *elusage)
{
	return memcmp(&key_info->elusage, elusage, sizeof(*elusage)) == 0;
}