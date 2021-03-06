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
typedef  int /*<<< orphan*/  rtx ;

/* Variables and functions */
 int /*<<< orphan*/  CCmode ; 
 int /*<<< orphan*/  CR0_REGNO ; 
 int /*<<< orphan*/  SImode ; 
 int /*<<< orphan*/  UNSPEC_AND ; 
 int /*<<< orphan*/  VOIDmode ; 
 int /*<<< orphan*/  XEXP (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  const0_rtx ; 
 int /*<<< orphan*/  emit_insn (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_label (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_load_locked (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_store_conditional (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  emit_unlikely_jump (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_iorsi3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_isync () ; 
 int /*<<< orphan*/  gen_label_rtx () ; 
 int /*<<< orphan*/  gen_memory_barrier () ; 
 int /*<<< orphan*/  gen_rtvec (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_AND (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_COMPARE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_LABEL_REF (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_NE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_NOT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_REG (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gen_rtx_UNSPEC (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void
rs6000_split_compare_and_swapqhi (rtx dest, rtx mask,
				  rtx oldval, rtx newval, rtx mem,
				  rtx scratch)
{
  rtx label1, label2, x, cond = gen_rtx_REG (CCmode, CR0_REGNO);

  emit_insn (gen_memory_barrier ());
  label1 = gen_rtx_LABEL_REF (VOIDmode, gen_label_rtx ());
  label2 = gen_rtx_LABEL_REF (VOIDmode, gen_label_rtx ());
  emit_label (XEXP (label1, 0));

  emit_load_locked (SImode, scratch, mem);

  /* Mask subword within loaded value for comparison with oldval.
     Use UNSPEC_AND to avoid clobber.*/
  emit_insn (gen_rtx_SET (SImode, dest,
			  gen_rtx_UNSPEC (SImode,
					  gen_rtvec (2, scratch, mask),
					  UNSPEC_AND)));

  x = gen_rtx_COMPARE (CCmode, dest, oldval);
  emit_insn (gen_rtx_SET (VOIDmode, cond, x));

  x = gen_rtx_NE (VOIDmode, cond, const0_rtx);
  emit_unlikely_jump (x, label2);

  /* Clear subword within loaded value for insertion of new value.  */
  emit_insn (gen_rtx_SET (SImode, scratch,
			  gen_rtx_AND (SImode,
				       gen_rtx_NOT (SImode, mask), scratch)));
  emit_insn (gen_iorsi3 (scratch, scratch, newval));
  emit_store_conditional (SImode, cond, mem, scratch);

  x = gen_rtx_NE (VOIDmode, cond, const0_rtx);
  emit_unlikely_jump (x, label1);

  emit_insn (gen_isync ());
  emit_label (XEXP (label2, 0));
}