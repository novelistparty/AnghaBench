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
 int EOF ; 
 int /*<<< orphan*/  _ (char*) ; 
 scalar_t__ ferror (int /*<<< orphan*/ ) ; 
 int getchar () ; 
 int /*<<< orphan*/  perror_fatal (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stdin ; 

__attribute__((used)) static void
flush_line (void)
{
  int c;
  while ((c = getchar ()) != '\n' && c != EOF)
    continue;
  if (ferror (stdin))
    perror_fatal (_("read failed"));
}