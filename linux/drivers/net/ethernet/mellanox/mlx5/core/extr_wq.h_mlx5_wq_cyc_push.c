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
struct mlx5_wq_cyc {int /*<<< orphan*/  cur_sz; int /*<<< orphan*/  wqe_ctr; } ;

/* Variables and functions */

__attribute__((used)) static inline void mlx5_wq_cyc_push(struct mlx5_wq_cyc *wq)
{
	wq->wqe_ctr++;
	wq->cur_sz++;
}