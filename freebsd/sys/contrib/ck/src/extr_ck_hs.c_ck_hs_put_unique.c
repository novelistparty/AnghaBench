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
struct ck_hs {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CK_HS_PROBE_TOMBSTONE ; 
 int ck_hs_put_internal (struct ck_hs*,unsigned long,void const*,int /*<<< orphan*/ ) ; 

bool
ck_hs_put_unique(struct ck_hs *hs,
    unsigned long h,
    const void *key)
{

	return ck_hs_put_internal(hs, h, key, CK_HS_PROBE_TOMBSTONE);
}