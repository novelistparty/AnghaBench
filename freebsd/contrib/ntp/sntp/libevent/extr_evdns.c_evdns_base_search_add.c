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
struct evdns_base {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  EVDNS_LOCK (struct evdns_base*) ; 
 int /*<<< orphan*/  EVDNS_UNLOCK (struct evdns_base*) ; 
 int /*<<< orphan*/  search_postfix_add (struct evdns_base*,char const*) ; 

void
evdns_base_search_add(struct evdns_base *base, const char *domain) {
	EVDNS_LOCK(base);
	search_postfix_add(base, domain);
	EVDNS_UNLOCK(base);
}