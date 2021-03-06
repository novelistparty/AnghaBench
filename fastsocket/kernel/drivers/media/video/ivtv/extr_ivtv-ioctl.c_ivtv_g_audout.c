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
struct v4l2_audioout {int /*<<< orphan*/  index; } ;
struct ivtv_open_id {struct ivtv* itv; } ;
struct ivtv {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int ivtv_get_audio_output (struct ivtv*,int /*<<< orphan*/ ,struct v4l2_audioout*) ; 

__attribute__((used)) static int ivtv_g_audout(struct file *file, void *fh, struct v4l2_audioout *vin)
{
	struct ivtv *itv = ((struct ivtv_open_id *)fh)->itv;

	vin->index = 0;
	return ivtv_get_audio_output(itv, vin->index, vin);
}