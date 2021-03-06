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
struct mcam_camera {scalar_t__ regs; } ;

/* Variables and functions */
 unsigned int ioread32 (scalar_t__) ; 

__attribute__((used)) static inline unsigned int mcam_reg_read(struct mcam_camera *cam,
		unsigned int reg)
{
	return ioread32(cam->regs + reg);
}