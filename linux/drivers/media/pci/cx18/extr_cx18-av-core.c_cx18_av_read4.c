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
typedef  scalar_t__ u16 ;
struct cx18 {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cx18_read_reg (struct cx18*,scalar_t__) ; 

u32 cx18_av_read4(struct cx18 *cx, u16 addr)
{
	return cx18_read_reg(cx, 0xc40000 + addr);
}