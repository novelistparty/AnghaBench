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
typedef  int /*<<< orphan*/  d3d_priv ;

/* Variables and functions */
 int /*<<< orphan*/  MP_VERBOSE (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  destroy_d3d (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void uninit_d3d(d3d_priv *priv)
{
    MP_VERBOSE(priv, "uninit_d3d called.\n");

    destroy_d3d(priv);
}