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
struct TYPE_3__ {int /*<<< orphan*/  sha384ctx; } ;
typedef  TYPE_1__ isc_hmacsha384_t ;

/* Variables and functions */
 int /*<<< orphan*/  isc_sha384_update (int /*<<< orphan*/ *,unsigned char const*,unsigned int) ; 

void
isc_hmacsha384_update(isc_hmacsha384_t *ctx, const unsigned char *buf,
		   unsigned int len)
{
	isc_sha384_update(&ctx->sha384ctx, buf, len);
}