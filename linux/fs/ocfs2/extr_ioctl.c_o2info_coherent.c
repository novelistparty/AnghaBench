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
struct ocfs2_info_request {int ir_flags; } ;

/* Variables and functions */
 int OCFS2_INFO_FL_NON_COHERENT ; 

__attribute__((used)) static inline int o2info_coherent(struct ocfs2_info_request *req)
{
	return (!(req->ir_flags & OCFS2_INFO_FL_NON_COHERENT));
}