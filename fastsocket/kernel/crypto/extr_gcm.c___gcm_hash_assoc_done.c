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
struct crypto_gcm_req_priv_ctx {int dummy; } ;
struct aead_request {int /*<<< orphan*/  assoclen; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EBUSY ; 
 int EINPROGRESS ; 
 int /*<<< orphan*/  __gcm_hash_assoc_remain_done (struct aead_request*,int) ; 
 struct crypto_gcm_req_priv_ctx* crypto_gcm_reqctx (struct aead_request*) ; 
 int /*<<< orphan*/  gcm_hash_assoc_remain_done ; 
 int gcm_hash_remain (struct aead_request*,struct crypto_gcm_req_priv_ctx*,unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int gcm_remain (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void __gcm_hash_assoc_done(struct aead_request *req, int err)
{
	struct crypto_gcm_req_priv_ctx *pctx = crypto_gcm_reqctx(req);
	unsigned int remain;

	if (!err) {
		remain = gcm_remain(req->assoclen);
		BUG_ON(!remain);
		err = gcm_hash_remain(req, pctx, remain,
				      gcm_hash_assoc_remain_done);
		if (err == -EINPROGRESS || err == -EBUSY)
			return;
	}

	__gcm_hash_assoc_remain_done(req, err);
}