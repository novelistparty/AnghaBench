#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct seq_file {int dummy; } ;
struct TYPE_3__ {int state; } ;
struct TYPE_4__ {TYPE_1__ tcp; } ;
struct nf_conn {int /*<<< orphan*/  lock; TYPE_2__ proto; } ;
typedef  enum tcp_conntrack { ____Placeholder_tcp_conntrack } tcp_conntrack ;

/* Variables and functions */
 int seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * tcp_conntrack_names ; 

__attribute__((used)) static int tcp_print_conntrack(struct seq_file *s, struct nf_conn *ct)
{
	enum tcp_conntrack state;

	spin_lock_bh(&ct->lock);
	state = ct->proto.tcp.state;
	spin_unlock_bh(&ct->lock);

	return seq_printf(s, "%s ", tcp_conntrack_names[state]);
}