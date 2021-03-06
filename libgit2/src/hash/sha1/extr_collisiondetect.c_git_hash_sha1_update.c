#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  c; } ;
typedef  TYPE_1__ git_hash_sha1_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  SHA1DCUpdate (int /*<<< orphan*/ *,void const*,size_t) ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 

int git_hash_sha1_update(git_hash_sha1_ctx *ctx, const void *data, size_t len)
{
	assert(ctx);
	SHA1DCUpdate(&ctx->c, data, len);
	return 0;
}