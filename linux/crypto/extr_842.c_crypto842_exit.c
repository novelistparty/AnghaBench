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
struct crypto_tfm {int dummy; } ;
struct crypto842_ctx {int /*<<< orphan*/  wmem; } ;

/* Variables and functions */
 int /*<<< orphan*/  crypto842_free_ctx (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct crypto842_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 

__attribute__((used)) static void crypto842_exit(struct crypto_tfm *tfm)
{
	struct crypto842_ctx *ctx = crypto_tfm_ctx(tfm);

	crypto842_free_ctx(NULL, ctx->wmem);
}