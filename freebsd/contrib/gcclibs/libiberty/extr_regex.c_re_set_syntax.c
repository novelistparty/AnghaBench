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
typedef  int reg_syntax_t ;

/* Variables and functions */
 int RE_DEBUG ; 
 int debug ; 
 int re_syntax_options ; 

reg_syntax_t
re_set_syntax (reg_syntax_t syntax)
{
  reg_syntax_t ret = re_syntax_options;

  re_syntax_options = syntax;
# ifdef DEBUG
  if (syntax & RE_DEBUG)
    debug = 1;
  else if (debug) /* was on but now is not */
    debug = 0;
# endif /* DEBUG */
  return ret;
}