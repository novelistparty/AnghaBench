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
struct nv50_mc_priv {int /*<<< orphan*/  base; } ;
struct nouveau_object {int dummy; } ;

/* Variables and functions */
 int nouveau_mc_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nv_wr32 (struct nv50_mc_priv*,int,int) ; 

int
nv50_mc_init(struct nouveau_object *object)
{
	struct nv50_mc_priv *priv = (void *)object;
	nv_wr32(priv, 0x000200, 0xffffffff); /* everything on */
	return nouveau_mc_init(&priv->base);
}