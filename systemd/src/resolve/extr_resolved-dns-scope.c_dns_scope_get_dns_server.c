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
struct TYPE_4__ {scalar_t__ protocol; int /*<<< orphan*/  manager; scalar_t__ link; } ;
typedef  int /*<<< orphan*/  DnsServer ;
typedef  TYPE_1__ DnsScope ;

/* Variables and functions */
 scalar_t__ DNS_PROTOCOL_DNS ; 
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int /*<<< orphan*/ * link_get_dns_server (scalar_t__) ; 
 int /*<<< orphan*/ * manager_get_dns_server (int /*<<< orphan*/ ) ; 

DnsServer *dns_scope_get_dns_server(DnsScope *s) {
        assert(s);

        if (s->protocol != DNS_PROTOCOL_DNS)
                return NULL;

        if (s->link)
                return link_get_dns_server(s->link);
        else
                return manager_get_dns_server(s->manager);
}