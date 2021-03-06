#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct ecore_hwfn {TYPE_3__* p_dcbx_info; } ;
struct TYPE_5__ {int valid; int /*<<< orphan*/  params; } ;
struct ecore_dcbx_get {TYPE_1__ remote; } ;
struct TYPE_8__ {int /*<<< orphan*/  app_pri_tbl; } ;
struct dcbx_features {int /*<<< orphan*/  pfc; int /*<<< orphan*/  ets; TYPE_4__ app; } ;
struct TYPE_6__ {struct dcbx_features features; } ;
struct TYPE_7__ {TYPE_2__ remote; } ;

/* Variables and functions */
 int /*<<< orphan*/  ecore_dcbx_get_common_params (struct ecore_hwfn*,TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void
ecore_dcbx_get_remote_params(struct ecore_hwfn *p_hwfn,
			     struct ecore_dcbx_get *params)
{
	struct dcbx_features *p_feat;

	p_feat = &p_hwfn->p_dcbx_info->remote.features;
	ecore_dcbx_get_common_params(p_hwfn, &p_feat->app,
				     p_feat->app.app_pri_tbl, &p_feat->ets,
				     p_feat->pfc, &params->remote.params,
				     false);
	params->remote.valid = true;
}