#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* hx509_revoke_ctx ;
struct TYPE_4__ {scalar_t__ ref; } ;

/* Variables and functions */
 scalar_t__ UINT_MAX ; 
 int /*<<< orphan*/  _hx509_abort (char*) ; 

hx509_revoke_ctx
_hx509_revoke_ref(hx509_revoke_ctx ctx)
{
    if (ctx == NULL)
	return NULL;
    if (ctx->ref == 0)
	_hx509_abort("revoke ctx refcount == 0 on ref");
    ctx->ref++;
    if (ctx->ref == UINT_MAX)
	_hx509_abort("revoke ctx refcount == UINT_MAX on ref");
    return ctx;
}