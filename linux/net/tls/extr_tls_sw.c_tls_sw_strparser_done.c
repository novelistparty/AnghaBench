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
struct tls_sw_context_rx {int /*<<< orphan*/  strp; } ;
struct tls_context {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  strp_done (int /*<<< orphan*/ *) ; 
 struct tls_sw_context_rx* tls_sw_ctx_rx (struct tls_context*) ; 

void tls_sw_strparser_done(struct tls_context *tls_ctx)
{
	struct tls_sw_context_rx *ctx = tls_sw_ctx_rx(tls_ctx);

	strp_done(&ctx->strp);
}