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
struct crypto_async_request {struct aead_request* data; } ;
struct aead_request {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  authenc_request_complete (struct aead_request*,int) ; 
 int crypto_authenc_decrypt_tail (struct aead_request*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void authenc_verify_ahash_done(struct crypto_async_request *areq,
				      int err)
{
	struct aead_request *req = areq->data;

	if (err)
		goto out;

	err = crypto_authenc_decrypt_tail(req, 0);

out:
	authenc_request_complete(req, err);
}