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
struct crypto_tfm {int dummy; } ;
struct crypto_aead {int dummy; } ;
struct crypto4xx_ctx {int sa_len; scalar_t__ sa_out; scalar_t__ sa_in; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_FEEDBACK_MODE_NO_FB ; 
 int /*<<< orphan*/  CRYPTO_MODE_CTR ; 
 int /*<<< orphan*/  CRYPTO_TFM_RES_BAD_KEY_LEN ; 
 int /*<<< orphan*/  DIR_INBOUND ; 
 int /*<<< orphan*/  DIR_OUTBOUND ; 
 int EINVAL ; 
 scalar_t__ SA_AES128_GCM_LEN ; 
 unsigned int SA_AES_GCM_CONTENTS ; 
 int /*<<< orphan*/  SA_CIPHER_ALG_AES ; 
 int /*<<< orphan*/  SA_COPY_PAYLOAD ; 
 int /*<<< orphan*/  SA_EXTENDED_SN_OFF ; 
 int /*<<< orphan*/  SA_HASH_ALG_GHASH ; 
 int /*<<< orphan*/  SA_HASH_MODE_HASH ; 
 int /*<<< orphan*/  SA_LOAD_HASH_FROM_SA ; 
 int /*<<< orphan*/  SA_LOAD_IV_FROM_STATE ; 
 int /*<<< orphan*/  SA_MC_DISABLE ; 
 int /*<<< orphan*/  SA_NOT_COPY_HDR ; 
 int /*<<< orphan*/  SA_NOT_COPY_PAD ; 
 int /*<<< orphan*/  SA_NOT_SAVE_IV ; 
 int /*<<< orphan*/  SA_NO_HEADER_PROC ; 
 int /*<<< orphan*/  SA_OPCODE_ENCRYPT_HASH ; 
 int /*<<< orphan*/  SA_OPCODE_HASH_DECRYPT ; 
 int /*<<< orphan*/  SA_OP_GROUP_BASIC ; 
 int /*<<< orphan*/  SA_PAD_TYPE_ZERO ; 
 int /*<<< orphan*/  SA_SAVE_HASH ; 
 int /*<<< orphan*/  SA_SEQ_MASK_ON ; 
 int crypto4xx_aead_setup_fallback (struct crypto4xx_ctx*,struct crypto_aead*,int /*<<< orphan*/  const*,unsigned int) ; 
 scalar_t__ crypto4xx_aes_gcm_validate_keylen (unsigned int) ; 
 int crypto4xx_alloc_sa (struct crypto4xx_ctx*,scalar_t__) ; 
 int crypto4xx_compute_gcm_hash_key_sw (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto4xx_free_sa (struct crypto4xx_ctx*) ; 
 int /*<<< orphan*/  crypto4xx_memcpy_to_le32 (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,unsigned int) ; 
 int /*<<< orphan*/  crypto_aead_set_flags (struct crypto_aead*,int /*<<< orphan*/ ) ; 
 struct crypto_tfm* crypto_aead_tfm (struct crypto_aead*) ; 
 struct crypto4xx_ctx* crypto_tfm_ctx (struct crypto_tfm*) ; 
 int /*<<< orphan*/  get_dynamic_sa_inner_digest (struct dynamic_sa_ctl*) ; 
 int /*<<< orphan*/  get_dynamic_sa_key_field (struct dynamic_sa_ctl*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  set_dynamic_sa_command_0 (struct dynamic_sa_ctl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_dynamic_sa_command_1 (struct dynamic_sa_ctl*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int crypto4xx_setkey_aes_gcm(struct crypto_aead *cipher,
			     const u8 *key, unsigned int keylen)
{
	struct crypto_tfm *tfm = crypto_aead_tfm(cipher);
	struct crypto4xx_ctx *ctx = crypto_tfm_ctx(tfm);
	struct dynamic_sa_ctl *sa;
	int    rc = 0;

	if (crypto4xx_aes_gcm_validate_keylen(keylen) != 0) {
		crypto_aead_set_flags(cipher, CRYPTO_TFM_RES_BAD_KEY_LEN);
		return -EINVAL;
	}

	rc = crypto4xx_aead_setup_fallback(ctx, cipher, key, keylen);
	if (rc)
		return rc;

	if (ctx->sa_in || ctx->sa_out)
		crypto4xx_free_sa(ctx);

	rc = crypto4xx_alloc_sa(ctx, SA_AES128_GCM_LEN + (keylen - 16) / 4);
	if (rc)
		return rc;

	sa  = (struct dynamic_sa_ctl *) ctx->sa_in;

	sa->sa_contents.w = SA_AES_GCM_CONTENTS | (keylen << 2);
	set_dynamic_sa_command_0(sa, SA_SAVE_HASH, SA_NOT_SAVE_IV,
				 SA_LOAD_HASH_FROM_SA, SA_LOAD_IV_FROM_STATE,
				 SA_NO_HEADER_PROC, SA_HASH_ALG_GHASH,
				 SA_CIPHER_ALG_AES, SA_PAD_TYPE_ZERO,
				 SA_OP_GROUP_BASIC, SA_OPCODE_HASH_DECRYPT,
				 DIR_INBOUND);
	set_dynamic_sa_command_1(sa, CRYPTO_MODE_CTR, SA_HASH_MODE_HASH,
				 CRYPTO_FEEDBACK_MODE_NO_FB, SA_EXTENDED_SN_OFF,
				 SA_SEQ_MASK_ON, SA_MC_DISABLE,
				 SA_NOT_COPY_PAD, SA_COPY_PAYLOAD,
				 SA_NOT_COPY_HDR);

	sa->sa_command_1.bf.key_len = keylen >> 3;

	crypto4xx_memcpy_to_le32(get_dynamic_sa_key_field(sa),
				 key, keylen);

	rc = crypto4xx_compute_gcm_hash_key_sw(get_dynamic_sa_inner_digest(sa),
		key, keylen);
	if (rc) {
		pr_err("GCM hash key setting failed = %d\n", rc);
		goto err;
	}

	memcpy(ctx->sa_out, ctx->sa_in, ctx->sa_len * 4);
	sa = (struct dynamic_sa_ctl *) ctx->sa_out;
	sa->sa_command_0.bf.dir = DIR_OUTBOUND;
	sa->sa_command_0.bf.opcode = SA_OPCODE_ENCRYPT_HASH;

	return 0;
err:
	crypto4xx_free_sa(ctx);
	return rc;
}