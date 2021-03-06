#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ mod; } ;
struct TYPE_5__ {scalar_t__ kind; TYPE_1__ int_lit; } ;
typedef  TYPE_2__ Expr ;

/* Variables and functions */
 scalar_t__ EXPR_INT ; 
 scalar_t__ MOD_CHAR ; 

__attribute__((used)) static bool is_char_lit(Expr *expr) {
    return expr->kind == EXPR_INT && expr->int_lit.mod == MOD_CHAR;
}