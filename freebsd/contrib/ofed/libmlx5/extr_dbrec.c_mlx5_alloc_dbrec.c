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
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/ * buf; } ;
struct mlx5_db_page {scalar_t__ use_cnt; scalar_t__ num_db; unsigned long* free; TYPE_1__ buf; struct mlx5_db_page* next; } ;
struct mlx5_context {int cache_line_size; int /*<<< orphan*/  db_list_mutex; struct mlx5_db_page* db_list; } ;

/* Variables and functions */
 struct mlx5_db_page* __add_page (struct mlx5_context*) ; 
 int ffsl (unsigned long) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

uint32_t *mlx5_alloc_dbrec(struct mlx5_context *context)
{
	struct mlx5_db_page *page;
	uint32_t *db = NULL;
	int i, j;

	pthread_mutex_lock(&context->db_list_mutex);

	for (page = context->db_list; page; page = page->next)
		if (page->use_cnt < page->num_db)
			goto found;

	page = __add_page(context);
	if (!page)
		goto out;

found:
	++page->use_cnt;

	for (i = 0; !page->free[i]; ++i)
		/* nothing */;

	j = ffsl(page->free[i]);
	--j;
	page->free[i] &= ~(1UL << j);
	db = page->buf.buf + (i * 8 * sizeof(long) + j) * context->cache_line_size;

out:
	pthread_mutex_unlock(&context->db_list_mutex);

	return db;
}