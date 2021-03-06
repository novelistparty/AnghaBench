#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct TYPE_9__ {int /*<<< orphan*/  opcode; int /*<<< orphan*/  dir; } ;
struct TYPE_10__ {TYPE_4__ bf; } ;
struct TYPE_7__ {unsigned int key_len; } ;
struct TYPE_8__ {TYPE_2__ bf; } ;
struct TYPE_6__ {unsigned int w; } ;
struct dynamic_sa_ctl {TYPE_5__ sa_command_0; TYPE_3__ sa_command_1; TYPE_1__ sa_contents; } ;
struct crypto_skcipher {int dummy; } ;
struct crypto4xx_ctx {int sa_len; struct dynamic_sa_ctl* sa_out; struct dynamic_sa_ctl* sa_in; } ;

/* Variables and functions */
 unsigned int AES_KEYSIZE_128 ; 
 unsigned int AES_KEYSIZE_192 ; 
 unsigned int AES_KEYSIZE_256 ; 
 unsigned char CRYPTO_MODE_ECB ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 int /*<<< orphan*/  DIR_INBOUND ; 
 int /*<<< orphan*/  DIR_OUTBOUND ; 
 int EINVAL ; 
 scalar_t__ SA_AES128_LEN ; 
 unsigned int SA_AES_CONTENTS ; 
 int /*<<< orphan*/  SA_CIPHER_ALG_AES ; 
 int /*<<< orphan*/  SA_EXTENDED_SN_OFF ; 
 int /*<<< orphan*/  SA_HASH_ALG_NULL ; 
 int /*<<< orphan*/  SA_HASH_MODE_HASH ; 
 int /*<<< orphan*/  SA_LOAD_IV_FROM_SA ; 
 int /*<<< orphan*/  SA_LOAD_IV_FROM_STATE ; 
 int /*<<< orphan*/  SA_MC_ENABLE ; 
 int /*<<< orphan*/  SA_NOT_COPY_HDR ; 
 int /*<<< orphan*/  SA_NOT_COPY_PAD ; 
 int /*<<< orphan*/  SA_NOT_COPY_PAYLOAD ; 
 int /*<<< orphan*/  SA_NOT_LOAD_HASH ; 
 int /*<<< orphan*/  SA_NOT_SAVE_HASH ; 
 int /*<<< orphan*/  SA_NOT_SAVE_IV ; 
 int /*<<< orphan*/  SA_NO_HEADER_PROC ; 
 int /*<<< orphan*/  SA_OPCODE_DECRYPT ; 
 int /*<<< orphan*/  SA_OPCODE_ENCRYPT ; 
 int /*<<< orphan*/  SA_OP_GROUP_BASIC ; 
 int /*<<< orphan*/  SA_PAD_TYPE_ZERO ; 
 int /*<<< orphan*/  SA_SAVE_IV ; 
 int /*<<< orphan*/  SA_SEQ_MASK_OFF ; 
 int crypto4xx_alloc_sa (struct crypto4xx_ctx*,scalar_t__) ; 
 int /*<<< orphan*/  crypto4xx_free_sa (struct crypto4xx_ctx*) ; 
 int /*<<< orphan*/  crypto4xx_memcpy_to_le32 (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ; 
 struct crypto4xx_ctx* crypto_skcipher_ctx (struct crypto_skcipher*) ; 
 int /*<<< orphan*/  crypto_skcipher_set_flags (struct crypto_skcipher*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_dynamic_sa_key_field (struct dynamic_sa_ctl*) ; 
 int /*<<< orphan*/  memcpy (struct dynamic_sa_ctl*,struct dynamic_sa_ctl*,int) ; 
 int /*<<< orphan*/  set_dynamic_sa_command_0 (struct dynamic_sa_ctl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_dynamic_sa_command_1 (struct dynamic_sa_ctl*,unsigned char,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int crypto4xx_setkey_aes(struct crypto_skcipher *cipher,
				const u8 *key,
				unsigned int keylen,
				unsigned char cm,
				u8 fb)
{
	struct crypto4xx_ctx *ctx = crypto_skcipher_ctx(cipher);
	struct dynamic_sa_ctl *sa;
	int    rc;

	if (keylen != AES_KEYSIZE_256 &&
		keylen != AES_KEYSIZE_192 && keylen != AES_KEYSIZE_128) {
		crypto_skcipher_set_flags(cipher,
				CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}

	/* Create SA */
	if (ctx->sa_in || ctx->sa_out)
		crypto4xx_free_sa(ctx);

	rc = crypto4xx_alloc_sa(ctx, SA_AES128_LEN + (keylen-16) / 4);
	if (rc)
		return rc;

	/* Setup SA */
	sa = ctx->sa_in;

	set_dynamic_sa_command_0(sa, SA_NOT_SAVE_HASH, (cm == CRYPTO_MODE_ECB ?
				 SA_NOT_SAVE_IV : SA_SAVE_IV),
				 SA_NOT_LOAD_HASH, (cm == CRYPTO_MODE_ECB ?
				 SA_LOAD_IV_FROM_SA : SA_LOAD_IV_FROM_STATE),
				 SA_NO_HEADER_PROC, SA_HASH_ALG_NULL,
				 SA_CIPHER_ALG_AES, SA_PAD_TYPE_ZERO,
				 SA_OP_GROUP_BASIC, SA_OPCODE_DECRYPT,
				 DIR_INBOUND);

	set_dynamic_sa_command_1(sa, cm, SA_HASH_MODE_HASH,
				 fb, SA_EXTENDED_SN_OFF,
				 SA_SEQ_MASK_OFF, SA_MC_ENABLE,
				 SA_NOT_COPY_PAD, SA_NOT_COPY_PAYLOAD,
				 SA_NOT_COPY_HDR);
	crypto4xx_memcpy_to_le32(get_dynamic_sa_key_field(sa),
				 key, keylen);
	sa->sa_contents.w = SA_AES_CONTENTS | (keylen << 2);
	sa->sa_command_1.bf.key_len = keylen >> 3;

	memcpy(ctx->sa_out, ctx->sa_in, ctx->sa_len * 4);
	sa = ctx->sa_out;
	sa->sa_command_0.bf.dir = DIR_OUTBOUND;
	/*
	 * SA_OPCODE_ENCRYPT is the same value as SA_OPCODE_DECRYPT.
	 * it's the DIR_(IN|OUT)BOUND that matters
	 */
	sa->sa_command_0.bf.opcode = SA_OPCODE_ENCRYPT;

	return 0;
}