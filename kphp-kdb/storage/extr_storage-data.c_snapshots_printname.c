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
 int /*<<< orphan*/ * filename_newidx ; 
 scalar_t__* newidx_fd ; 
 int newidx_fds ; 
 int /*<<< orphan*/  print_snapshot_name (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void snapshots_printname (void) {
  int k;
  for (k = 0; k < newidx_fds; k++) {
    if (newidx_fd[k] >= 0) {
      print_snapshot_name (filename_newidx[k]);
    }
  }
}