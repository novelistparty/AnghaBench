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
 int /*<<< orphan*/  EXIT_SUCCESS ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  flush_binlog_ts () ; 
 int /*<<< orphan*/  printf (char*) ; 

__attribute__((used)) static void sigint_handler (const int sig) {
  printf("SIGINT handled.\n");
  flush_binlog_ts();
  exit(EXIT_SUCCESS);
}