#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int algo; int /*<<< orphan*/  sha1; } ;
typedef  TYPE_1__ git_hash_ctx ;

/* Variables and functions */
#define  GIT_HASH_ALGO_SHA1 128 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int git_hash_sha1_update (int /*<<< orphan*/ *,void const*,size_t) ; 

int git_hash_update(git_hash_ctx *ctx, const void *data, size_t len)
{
	switch (ctx->algo) {
		case GIT_HASH_ALGO_SHA1:
			return git_hash_sha1_update(&ctx->sha1, data, len);
		default:
			assert(0);
			return -1;
	}
}