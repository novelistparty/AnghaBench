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
typedef  int /*<<< orphan*/  u64 ;
typedef  scalar_t__ ssize_t ;

/* Variables and functions */
 scalar_t__ ft_parse_wwn (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t ft_wwn_store(void *arg, const char *buf, size_t len)
{
	ssize_t ret;
	u64 wwn;

	ret = ft_parse_wwn(buf, &wwn, 0);
	if (ret > 0)
		*(u64 *)arg = wwn;
	return ret;
}