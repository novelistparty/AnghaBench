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
 int /*<<< orphan*/  sevenbit_strings ; 

__attribute__((used)) static int
iso_8859_print_literally (void *baton, int c)
{
  c &= 0xff;

  return ((0x20 <= c && c <= 0x7e) /* ascii printables */
          || (! sevenbit_strings && 0xA0 <= c)); /* iso 8859 printables */
}