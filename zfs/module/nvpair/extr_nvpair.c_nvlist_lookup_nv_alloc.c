#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * nvp_nva; } ;
typedef  TYPE_1__ nvpriv_t ;
struct TYPE_5__ {scalar_t__ nvl_priv; } ;
typedef  TYPE_2__ nvlist_t ;
typedef  int /*<<< orphan*/  nv_alloc_t ;

/* Variables and functions */

nv_alloc_t *
nvlist_lookup_nv_alloc(nvlist_t *nvl)
{
	nvpriv_t *priv;

	if (nvl == NULL ||
	    (priv = (nvpriv_t *)(uintptr_t)nvl->nvl_priv) == NULL)
		return (NULL);

	return (priv->nvp_nva);
}