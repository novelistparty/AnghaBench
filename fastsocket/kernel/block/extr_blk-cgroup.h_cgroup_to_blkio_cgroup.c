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
struct cgroup {int dummy; } ;
struct blkio_cgroup {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct blkio_cgroup *
cgroup_to_blkio_cgroup(struct cgroup *cgroup) { return NULL; }