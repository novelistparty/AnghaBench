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

/* Variables and functions */
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  _bfd_error_handler (int /*<<< orphan*/ ,char const*,char const*) ; 

__attribute__((used)) static void
undefined_reference (const char *  reftype,
		     const char *  name)
{
  _bfd_error_handler (_("undefined %s reference in complex symbol: %s"), reftype, name);
}