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
struct shader_reg {int dummy; } ;
struct instruction {int /*<<< orphan*/  has_dst; struct shader_reg dst; } ;
struct asm_parser {int /*<<< orphan*/  status; int /*<<< orphan*/  line_no; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  PARSE_ERR ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  asmparser_message (struct asm_parser*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  check_reg_type (struct shader_reg const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debug_print_dstreg (struct shader_reg const*) ; 
 struct shader_reg map_oldps_register (struct shader_reg const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ps_1_0123_reg_allowed ; 
 int /*<<< orphan*/  set_parse_status (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void asmparser_dstreg_ps_1_0123(struct asm_parser *This,
                                       struct instruction *instr,
                                       const struct shader_reg *dst) {
    struct shader_reg reg;

    if(!check_reg_type(dst, ps_1_0123_reg_allowed)) {
        asmparser_message(This, "Line %u: Destination register %s not supported in PS 1\n",
                          This->line_no,
                          debug_print_dstreg(dst));
        set_parse_status(&This->status, PARSE_ERR);
    }
    reg = map_oldps_register(dst, FALSE);
    instr->dst = reg;
    instr->has_dst = TRUE;
}