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
struct shash_desc {int dummy; } ;
struct cryptd_hash_request_ctx {struct shash_desc desc; } ;
struct ahash_request {int dummy; } ;

/* Variables and functions */
 struct cryptd_hash_request_ctx* ahash_request_ctx (struct ahash_request*) ; 

struct shash_desc *cryptd_shash_desc(struct ahash_request *req)
{
	struct cryptd_hash_request_ctx *rctx = ahash_request_ctx(req);
	return &rctx->desc;
}