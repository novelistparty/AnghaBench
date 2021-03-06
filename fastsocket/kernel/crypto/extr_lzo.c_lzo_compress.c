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
typedef  int /*<<< orphan*/  u8 ;
struct lzo_ctx {int /*<<< orphan*/  lzo_comp_mem; } ;
struct crypto_tfm {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int LZO_E_OK ; 
 struct lzo_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int lzo1x_1_compress (int /*<<< orphan*/  const*,unsigned int,int /*<<< orphan*/ *,size_t*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int lzo_compress(struct crypto_tfm *tfm, const u8 *src,
			    unsigned int slen, u8 *dst, unsigned int *dlen)
{
	struct lzo_ctx *ctx = crypto_tfm_ctx(tfm);
	size_t tmp_len = *dlen; /* size_t(ulong) <-> uint on 64 bit */
	int err;

	err = lzo1x_1_compress(src, slen, dst, &tmp_len, ctx->lzo_comp_mem);

	if (err != LZO_E_OK)
		return -EINVAL;

	*dlen = tmp_len;
	return 0;
}