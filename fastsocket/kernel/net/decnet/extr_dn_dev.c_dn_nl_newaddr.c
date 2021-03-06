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
struct sk_buff {int /*<<< orphan*/  sk; } ;
struct nlmsghdr {int dummy; } ;
struct nlattr {int dummy; } ;
struct net_device {int /*<<< orphan*/  name; struct dn_dev* dn_ptr; } ;
struct net {int dummy; } ;
struct ifaddrmsg {int /*<<< orphan*/  ifa_scope; int /*<<< orphan*/  ifa_flags; int /*<<< orphan*/  ifa_index; } ;
struct dn_ifaddr {int /*<<< orphan*/  ifa_label; struct dn_dev* ifa_dev; int /*<<< orphan*/  ifa_scope; int /*<<< orphan*/  ifa_flags; void* ifa_address; void* ifa_local; } ;
struct dn_dev {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOBUFS ; 
 int ENODEV ; 
 size_t IFA_ADDRESS ; 
 size_t IFA_LABEL ; 
 size_t IFA_LOCAL ; 
 int /*<<< orphan*/  IFA_MAX ; 
 int /*<<< orphan*/  IFNAMSIZ ; 
 struct net_device* __dev_get_by_index (struct net*,int /*<<< orphan*/ ) ; 
 struct dn_ifaddr* dn_dev_alloc_ifa () ; 
 struct dn_dev* dn_dev_create (struct net_device*,int*) ; 
 int /*<<< orphan*/  dn_dev_free_ifa (struct dn_ifaddr*) ; 
 int dn_dev_insert_ifa (struct dn_dev*,struct dn_ifaddr*) ; 
 int /*<<< orphan*/  dn_ifa_policy ; 
 struct net init_net ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* nla_get_le16 (struct nlattr*) ; 
 int /*<<< orphan*/  nla_strlcpy (int /*<<< orphan*/ ,struct nlattr*,int /*<<< orphan*/ ) ; 
 struct ifaddrmsg* nlmsg_data (struct nlmsghdr*) ; 
 int nlmsg_parse (struct nlmsghdr*,int,struct nlattr**,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct net* sock_net (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int dn_nl_newaddr(struct sk_buff *skb, struct nlmsghdr *nlh, void *arg)
{
	struct net *net = sock_net(skb->sk);
	struct nlattr *tb[IFA_MAX+1];
	struct net_device *dev;
	struct dn_dev *dn_db;
	struct ifaddrmsg *ifm;
	struct dn_ifaddr *ifa;
	int err;

	if (net != &init_net)
		return -EINVAL;

	err = nlmsg_parse(nlh, sizeof(*ifm), tb, IFA_MAX, dn_ifa_policy);
	if (err < 0)
		return err;

	if (tb[IFA_LOCAL] == NULL)
		return -EINVAL;

	ifm = nlmsg_data(nlh);
	if ((dev = __dev_get_by_index(&init_net, ifm->ifa_index)) == NULL)
		return -ENODEV;

	if ((dn_db = dev->dn_ptr) == NULL) {
		dn_db = dn_dev_create(dev, &err);
		if (!dn_db)
			return err;
	}

	if ((ifa = dn_dev_alloc_ifa()) == NULL)
		return -ENOBUFS;

	if (tb[IFA_ADDRESS] == NULL)
		tb[IFA_ADDRESS] = tb[IFA_LOCAL];

	ifa->ifa_local = nla_get_le16(tb[IFA_LOCAL]);
	ifa->ifa_address = nla_get_le16(tb[IFA_ADDRESS]);
	ifa->ifa_flags = ifm->ifa_flags;
	ifa->ifa_scope = ifm->ifa_scope;
	ifa->ifa_dev = dn_db;

	if (tb[IFA_LABEL])
		nla_strlcpy(ifa->ifa_label, tb[IFA_LABEL], IFNAMSIZ);
	else
		memcpy(ifa->ifa_label, dev->name, IFNAMSIZ);

	err = dn_dev_insert_ifa(dn_db, ifa);
	if (err)
		dn_dev_free_ifa(ifa);

	return err;
}