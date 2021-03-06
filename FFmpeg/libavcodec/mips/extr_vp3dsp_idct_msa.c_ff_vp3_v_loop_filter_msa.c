#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  int v8i16 ;
typedef  scalar_t__ v4i32 ;
struct TYPE_23__ {int member_1; int member_2; int member_3; int member_4; int member_5; int member_6; int member_7; int /*<<< orphan*/  member_15; int /*<<< orphan*/  member_14; int /*<<< orphan*/  member_13; int /*<<< orphan*/  member_12; int /*<<< orphan*/  member_11; int /*<<< orphan*/  member_10; int /*<<< orphan*/  member_9; int /*<<< orphan*/  member_8; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ v16i8 ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int ptrdiff_t ;
typedef  size_t int16_t ;

/* Variables and functions */
 int /*<<< orphan*/  CLIP_SW4_0_255 (scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ILVL_H2_SW (TYPE_1__,int,TYPE_1__,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ILVR_B4_SH (TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__,int,int,int,int) ; 
 int /*<<< orphan*/  ILVR_H2_SW (TYPE_1__,int,TYPE_1__,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  LD_SB4 (int /*<<< orphan*/ *,int,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__) ; 
 int /*<<< orphan*/  LD_SW2 (int*,int,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ST_D1 (TYPE_1__,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ST_SH (int,size_t*) ; 
 int /*<<< orphan*/  VSHF_B2_SB (scalar_t__,scalar_t__,scalar_t__,scalar_t__,TYPE_1__,TYPE_1__,TYPE_1__,TYPE_1__) ; 

void ff_vp3_v_loop_filter_msa(uint8_t *first_pixel, ptrdiff_t stride,
                              int *bounding_values)
{
    int nstride = -stride;
    v4i32 e0, e1, f0, f1, g0, g1;
    v16i8 zero = {0};
    v16i8 d0, d1, d2, d3;
    v8i16 c0, c1, c2, c3;
    v8i16 r0;
    v8i16 cnst3h = {3, 3, 3, 3, 3, 3, 3, 3},
          cnst4h = {4, 4, 4, 4, 4, 4, 4, 4};
    v16i8 mask = {0, 4, 8, 12, 16, 20, 24, 28, 0, 0, 0, 0, 0, 0, 0, 0};
    int16_t temp_16[8];
    int temp_32[8];

    LD_SB4(first_pixel + nstride * 2, stride, d0, d1, d2, d3);
    ILVR_B4_SH(zero, d0, zero, d1, zero, d2, zero, d3,
               c0, c1, c2, c3);
    r0 = (c0 - c3) + (c2 - c1) * cnst3h;
    r0 += cnst4h;
    r0 = r0 >> 3;
    /* Get filter_value from bounding_values one by one */
    ST_SH(r0, temp_16);
    for (int i = 0; i < 8; i++)
        temp_32[i] = bounding_values[temp_16[i]];
    LD_SW2(temp_32, 4, e0, e1);
    ILVR_H2_SW(zero, c1, zero, c2, f0, g0);
    ILVL_H2_SW(zero, c1, zero, c2, f1, g1);
    f0 += e0;
    f1 += e1;
    g0 -= e0;
    g1 -= e1;
    CLIP_SW4_0_255(f0, f1, g0, g1);
    VSHF_B2_SB(f0, f1, g0, g1, mask, mask, d1, d2);

    /* Final move to first_pixel */
    ST_D1(d1, 0, first_pixel + nstride);
    ST_D1(d2, 0, first_pixel);
}