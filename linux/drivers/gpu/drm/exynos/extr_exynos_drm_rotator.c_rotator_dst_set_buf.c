#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct rot_context {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  x; int /*<<< orphan*/  y; } ;
struct TYPE_6__ {int* pitch; int /*<<< orphan*/  height; } ;
struct exynos_drm_ipp_buffer {int* dma_addr; TYPE_2__ rect; TYPE_1__* format; TYPE_3__ buf; } ;
struct TYPE_4__ {int* cpp; } ;

/* Variables and functions */
 int ROT_CROP_POS_X (int /*<<< orphan*/ ) ; 
 int ROT_CROP_POS_Y (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ROT_DST_BUF_ADDR (int) ; 
 int /*<<< orphan*/  ROT_DST_BUF_SIZE ; 
 int /*<<< orphan*/  ROT_DST_CROP_POS ; 
 int ROT_SET_BUF_SIZE_H (int /*<<< orphan*/ ) ; 
 int ROT_SET_BUF_SIZE_W (int) ; 
 int /*<<< orphan*/  rot_write (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rotator_dst_set_buf(struct rot_context *rot,
				struct exynos_drm_ipp_buffer *buf)
{
	u32 val;

	/* Set buffer size configuration */
	val = ROT_SET_BUF_SIZE_H(buf->buf.height) |
	      ROT_SET_BUF_SIZE_W(buf->buf.pitch[0] / buf->format->cpp[0]);
	rot_write(val, ROT_DST_BUF_SIZE);

	/* Set crop image position configuration */
	val = ROT_CROP_POS_Y(buf->rect.y) | ROT_CROP_POS_X(buf->rect.x);
	rot_write(val, ROT_DST_CROP_POS);

	/* Set buffer DMA address */
	rot_write(buf->dma_addr[0], ROT_DST_BUF_ADDR(0));
	rot_write(buf->dma_addr[1], ROT_DST_BUF_ADDR(1));
}