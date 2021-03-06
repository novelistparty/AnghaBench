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
struct TYPE_3__ {int /*<<< orphan*/ * prec; int /*<<< orphan*/  initial; int /*<<< orphan*/  blind; } ;
typedef  TYPE_1__ secp256k1_ecmult_gen_context ;

/* Variables and functions */
 int /*<<< orphan*/  secp256k1_gej_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  secp256k1_scalar_clear (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void secp256k1_ecmult_gen_context_clear(secp256k1_ecmult_gen_context *ctx) {
    secp256k1_scalar_clear(&ctx->blind);
    secp256k1_gej_clear(&ctx->initial);
    ctx->prec = NULL;
}