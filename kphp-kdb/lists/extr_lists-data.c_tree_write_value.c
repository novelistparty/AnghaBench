#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tree_ext_small_t ;
struct TYPE_2__ {int /*<<< orphan*/  value; } ;

/* Variables and functions */
 TYPE_1__* LPAYLOAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writeout_value (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int tree_write_value (tree_ext_small_t *T) {
  writeout_value (LPAYLOAD(T)->value);
  return 0;
}