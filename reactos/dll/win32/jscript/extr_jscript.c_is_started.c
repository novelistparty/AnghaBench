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
struct TYPE_3__ {scalar_t__ state; } ;
typedef  TYPE_1__ script_ctx_t ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ SCRIPTSTATE_CONNECTED ; 
 scalar_t__ SCRIPTSTATE_DISCONNECTED ; 
 scalar_t__ SCRIPTSTATE_STARTED ; 

__attribute__((used)) static inline BOOL is_started(script_ctx_t *ctx)
{
    return ctx->state == SCRIPTSTATE_STARTED
        || ctx->state == SCRIPTSTATE_CONNECTED
        || ctx->state == SCRIPTSTATE_DISCONNECTED;
}