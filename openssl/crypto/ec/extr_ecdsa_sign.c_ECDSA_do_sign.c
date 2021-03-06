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
typedef  int /*<<< orphan*/  EC_KEY ;
typedef  int /*<<< orphan*/  ECDSA_SIG ;

/* Variables and functions */
 int /*<<< orphan*/ * ECDSA_do_sign_ex (unsigned char const*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

ECDSA_SIG *ECDSA_do_sign(const unsigned char *dgst, int dlen, EC_KEY *eckey)
{
    return ECDSA_do_sign_ex(dgst, dlen, NULL, NULL, eckey);
}