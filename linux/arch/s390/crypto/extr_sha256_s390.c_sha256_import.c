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
struct sha256_state {int /*<<< orphan*/  buf; int /*<<< orphan*/  state; int /*<<< orphan*/  count; } ;
struct s390_sha_ctx {int /*<<< orphan*/  func; int /*<<< orphan*/  buf; int /*<<< orphan*/  state; int /*<<< orphan*/  count; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPACF_KIMD_SHA_256 ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct s390_sha_ctx* shash_desc_ctx (struct shash_desc*) ; 

__attribute__((used)) static int sha256_import(struct shash_desc *desc, const void *in)
{
	struct s390_sha_ctx *sctx = shash_desc_ctx(desc);
	const struct sha256_state *ictx = in;

	sctx->count = ictx->count;
	memcpy(sctx->state, ictx->state, sizeof(ictx->state));
	memcpy(sctx->buf, ictx->buf, sizeof(ictx->buf));
	sctx->func = CPACF_KIMD_SHA_256;
	return 0;
}