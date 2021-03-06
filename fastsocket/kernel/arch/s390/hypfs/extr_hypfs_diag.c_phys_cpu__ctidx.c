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
struct x_phys_cpu {int /*<<< orphan*/  ctidx; } ;
struct phys_cpu {int /*<<< orphan*/  ctidx; } ;
typedef  enum diag204_format { ____Placeholder_diag204_format } diag204_format ;
typedef  int /*<<< orphan*/  __u64 ;

/* Variables and functions */
 int INFO_SIMPLE ; 

__attribute__((used)) static inline __u64 phys_cpu__ctidx(enum diag204_format type, void *hdr)
{
	if (type == INFO_SIMPLE)
		return ((struct phys_cpu *)hdr)->ctidx;
	else /* INFO_EXT */
		return ((struct x_phys_cpu *)hdr)->ctidx;
}