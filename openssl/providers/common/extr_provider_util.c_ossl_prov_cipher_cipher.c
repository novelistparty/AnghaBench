#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  const* cipher; } ;
typedef  TYPE_1__ PROV_CIPHER ;
typedef  int /*<<< orphan*/  EVP_CIPHER ;

/* Variables and functions */

const EVP_CIPHER *ossl_prov_cipher_cipher(const PROV_CIPHER *pc)
{
    return pc->cipher;
}