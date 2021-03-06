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
struct TYPE_3__ {int /*<<< orphan*/  by_key; } ;
typedef  TYPE_1__ DnsCache ;

/* Variables and functions */
 int hashmap_isempty (int /*<<< orphan*/ ) ; 

bool dns_cache_is_empty(DnsCache *cache) {
        if (!cache)
                return true;

        return hashmap_isempty(cache->by_key);
}