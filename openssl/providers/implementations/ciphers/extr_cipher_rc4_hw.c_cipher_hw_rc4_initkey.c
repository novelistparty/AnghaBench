#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  ks; } ;
struct TYPE_4__ {TYPE_1__ ks; } ;
typedef  TYPE_2__ PROV_RC4_CTX ;
typedef  int /*<<< orphan*/  PROV_CIPHER_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  RC4_set_key (int /*<<< orphan*/ *,size_t,unsigned char const*) ; 

__attribute__((used)) static int cipher_hw_rc4_initkey(PROV_CIPHER_CTX *ctx,
                                 const unsigned char *key, size_t keylen)
{
    PROV_RC4_CTX *rctx =  (PROV_RC4_CTX *)ctx;

    RC4_set_key(&rctx->ks.ks, keylen, key);
    return 1;
}