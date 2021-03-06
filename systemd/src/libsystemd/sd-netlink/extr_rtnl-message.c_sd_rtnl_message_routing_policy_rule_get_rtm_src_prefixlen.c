#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct rtmsg {unsigned char rtm_src_len; } ;
struct TYPE_6__ {struct TYPE_6__ const* hdr; int /*<<< orphan*/  nlmsg_type; } ;
typedef  TYPE_1__ sd_netlink_message ;

/* Variables and functions */
 int /*<<< orphan*/  EINVAL ; 
 struct rtmsg* NLMSG_DATA (TYPE_1__ const*) ; 
 int /*<<< orphan*/  assert_return (TYPE_1__ const*,int /*<<< orphan*/ ) ; 
 TYPE_1__ const* rtnl_message_type_is_routing_policy_rule (int /*<<< orphan*/ ) ; 

int sd_rtnl_message_routing_policy_rule_get_rtm_src_prefixlen(const sd_netlink_message *m, unsigned char *len) {
        struct rtmsg *routing_policy_rule;

        assert_return(m, -EINVAL);
        assert_return(m->hdr, -EINVAL);
        assert_return(rtnl_message_type_is_routing_policy_rule(m->hdr->nlmsg_type), -EINVAL);

        routing_policy_rule = NLMSG_DATA(m->hdr);

        *len = routing_policy_rule->rtm_src_len;

        return 0;
}