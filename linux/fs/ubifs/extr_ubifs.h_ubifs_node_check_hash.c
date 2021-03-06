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
typedef  int /*<<< orphan*/  u8 ;
struct ubifs_info {int dummy; } ;

/* Variables and functions */
 int __ubifs_node_check_hash (struct ubifs_info const*,void const*,int /*<<< orphan*/  const*) ; 
 scalar_t__ ubifs_authenticated (struct ubifs_info const*) ; 

__attribute__((used)) static inline int ubifs_node_check_hash(const struct ubifs_info *c,
					const void *buf, const u8 *expected)
{
	if (ubifs_authenticated(c))
		return __ubifs_node_check_hash(c, buf, expected);
	else
		return 0;
}