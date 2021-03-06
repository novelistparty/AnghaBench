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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  avc_h_loop_filter_chroma422_mbaff_msa (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

void ff_h264_h_loop_filter_chroma422_mbaff_msa(uint8_t *src,
                                               int32_t ystride,
                                               int32_t alpha,
                                               int32_t beta,
                                               int8_t *tc0)
{
    avc_h_loop_filter_chroma422_mbaff_msa(src, ystride, alpha, beta, tc0);
}