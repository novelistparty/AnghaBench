#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mlx5e_channel {int /*<<< orphan*/ * sq; TYPE_1__* priv; } ;
struct TYPE_2__ {int num_tc; } ;

/* Variables and functions */
 int /*<<< orphan*/  mlx5e_close_sq_wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
mlx5e_close_sqs_wait(struct mlx5e_channel *c)
{
	int tc;

	for (tc = 0; tc < c->priv->num_tc; tc++)
		mlx5e_close_sq_wait(&c->sq[tc]);
}