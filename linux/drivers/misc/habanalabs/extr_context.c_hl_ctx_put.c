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
struct hl_ctx {int /*<<< orphan*/  refcount; } ;

/* Variables and functions */
 int /*<<< orphan*/  hl_ctx_do_release ; 
 int kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int hl_ctx_put(struct hl_ctx *ctx)
{
	return kref_put(&ctx->refcount, hl_ctx_do_release);
}