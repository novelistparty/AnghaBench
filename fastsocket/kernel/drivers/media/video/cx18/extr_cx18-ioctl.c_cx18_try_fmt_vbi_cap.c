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
struct v4l2_format {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int cx18_g_fmt_vbi_cap (struct file*,void*,struct v4l2_format*) ; 

__attribute__((used)) static int cx18_try_fmt_vbi_cap(struct file *file, void *fh,
				struct v4l2_format *fmt)
{
	return cx18_g_fmt_vbi_cap(file, fh, fmt);
}