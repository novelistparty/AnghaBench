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
typedef  int /*<<< orphan*/  u32 ;
struct guc_ct_buffer_desc {int /*<<< orphan*/  status; int /*<<< orphan*/  is_in_error; int /*<<< orphan*/  fence; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRM_ERROR (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int EPROTO ; 
 scalar_t__ WARN_ON (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  done ; 
 int /*<<< orphan*/  guc_ct_buffer_desc_reset (struct guc_ct_buffer_desc*) ; 
 scalar_t__ unlikely (int) ; 
 int wait_for (int /*<<< orphan*/ ,int) ; 
 int wait_for_us (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int wait_for_ctb_desc_update(struct guc_ct_buffer_desc *desc,
				    u32 fence,
				    u32 *status)
{
	int err;

	/*
	 * Fast commands should complete in less than 10us, so sample quickly
	 * up to that length of time, then switch to a slower sleep-wait loop.
	 * No GuC command should ever take longer than 10ms.
	 */
#define done (READ_ONCE(desc->fence) == fence)
	err = wait_for_us(done, 10);
	if (err)
		err = wait_for(done, 10);
#undef done

	if (unlikely(err)) {
		DRM_ERROR("CT: fence %u failed; reported fence=%u\n",
			  fence, desc->fence);

		if (WARN_ON(desc->is_in_error)) {
			/* Something went wrong with the messaging, try to reset
			 * the buffer and hope for the best
			 */
			guc_ct_buffer_desc_reset(desc);
			err = -EPROTO;
		}
	}

	*status = desc->status;
	return err;
}