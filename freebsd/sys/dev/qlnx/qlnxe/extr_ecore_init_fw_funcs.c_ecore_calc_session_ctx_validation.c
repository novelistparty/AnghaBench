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
typedef  size_t u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  OSAL_MEMSET (size_t*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t** con_region_offsets ; 
 size_t ecore_calc_cdu_validation_byte (size_t,int,int /*<<< orphan*/ ) ; 

void ecore_calc_session_ctx_validation(void *p_ctx_mem, u16 ctx_size, u8 ctx_type, u32 cid)
{
	u8 *x_val_ptr, *t_val_ptr, *u_val_ptr, *p_ctx;

	p_ctx = (u8* const)p_ctx_mem;
	x_val_ptr = &p_ctx[con_region_offsets[0][ctx_type]];
	t_val_ptr = &p_ctx[con_region_offsets[1][ctx_type]];
	u_val_ptr = &p_ctx[con_region_offsets[2][ctx_type]];

	OSAL_MEMSET(p_ctx, 0, ctx_size);

	*x_val_ptr = ecore_calc_cdu_validation_byte(ctx_type, 3, cid);
	*t_val_ptr = ecore_calc_cdu_validation_byte(ctx_type, 4, cid);
	*u_val_ptr = ecore_calc_cdu_validation_byte(ctx_type, 5, cid);
}