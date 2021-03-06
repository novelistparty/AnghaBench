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
struct TYPE_3__ {int /*<<< orphan*/  allocator; } ;
typedef  int /*<<< orphan*/  Jbig2HuffmanState ;
typedef  TYPE_1__ Jbig2Ctx ;

/* Variables and functions */
 int /*<<< orphan*/  jbig2_free (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void
jbig2_huffman_free(Jbig2Ctx *ctx, Jbig2HuffmanState *hs)
{
    jbig2_free(ctx->allocator, hs);
}