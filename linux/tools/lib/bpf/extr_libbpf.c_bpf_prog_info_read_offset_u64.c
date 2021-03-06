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
struct bpf_prog_info {int dummy; } ;
typedef  int __u64 ;

/* Variables and functions */

__attribute__((used)) static __u64 bpf_prog_info_read_offset_u64(struct bpf_prog_info *info, int offset)
{
	__u64 *array = (__u64 *)info;

	if (offset >= 0)
		return array[offset / sizeof(__u64)];
	return -(int)offset;
}