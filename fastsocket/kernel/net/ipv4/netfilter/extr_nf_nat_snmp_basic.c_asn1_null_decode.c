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
struct asn1_ctx {unsigned char* pointer; } ;

/* Variables and functions */

__attribute__((used)) static unsigned char asn1_null_decode(struct asn1_ctx *ctx, unsigned char *eoc)
{
	ctx->pointer = eoc;
	return 1;
}