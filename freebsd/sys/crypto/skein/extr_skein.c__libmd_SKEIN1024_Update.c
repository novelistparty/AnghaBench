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
typedef  int /*<<< orphan*/  SKEIN1024_CTX ;

/* Variables and functions */
 int /*<<< orphan*/  Skein1024_Update (int /*<<< orphan*/ *,void const*,size_t) ; 

void
SKEIN1024_Update(SKEIN1024_CTX * ctx, const void *in, size_t len)
{

	Skein1024_Update(ctx, in, len);
}