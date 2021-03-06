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
typedef  TYPE_1__* hx509_verify_ctx ;
typedef  int /*<<< orphan*/  hx509_revoke_ctx ;
struct TYPE_3__ {scalar_t__ revoke_ctx; } ;

/* Variables and functions */
 scalar_t__ _hx509_revoke_ref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hx509_revoke_free (scalar_t__*) ; 

void
hx509_verify_attach_revoke(hx509_verify_ctx ctx, hx509_revoke_ctx revoke_ctx)
{
    if (ctx->revoke_ctx)
	hx509_revoke_free(&ctx->revoke_ctx);
    ctx->revoke_ctx = _hx509_revoke_ref(revoke_ctx);
}