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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/ * null_in ; 
 int /*<<< orphan*/ * null_out ; 
 int /*<<< orphan*/ * stdin ; 
 int /*<<< orphan*/ * stdout ; 
 scalar_t__ yy_buffer_stack ; 
 scalar_t__ yy_buffer_stack_max ; 
 scalar_t__ yy_buffer_stack_top ; 
 char* yy_c_buf_p ; 
 scalar_t__ yy_init ; 
 scalar_t__ yy_start ; 

__attribute__((used)) static int yy_init_globals (void)
{
        /* Initialization is the same as for the non-reentrant scanner.
     * This function is called from null_lex_destroy(), so don't allocate here.
     */

    (yy_buffer_stack) = 0;
    (yy_buffer_stack_top) = 0;
    (yy_buffer_stack_max) = 0;
    (yy_c_buf_p) = (char *) 0;
    (yy_init) = 0;
    (yy_start) = 0;

/* Defined in main.c */
#ifdef YY_STDINIT
    null_in = stdin;
    null_out = stdout;
#else
    null_in = (FILE *) 0;
    null_out = (FILE *) 0;
#endif

    /* For future reference: Set errno on error, since we are called by
     * null_lex_init()
     */
    return 0;
}