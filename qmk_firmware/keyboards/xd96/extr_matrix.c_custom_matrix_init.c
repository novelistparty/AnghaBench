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
 int /*<<< orphan*/  IC1 ; 
 int /*<<< orphan*/  IC2 ; 
 int /*<<< orphan*/  init_pins () ; 
 int /*<<< orphan*/  pca9555_init (int /*<<< orphan*/ ) ; 

void custom_matrix_init(void) {
  pca9555_init(IC1);
  pca9555_init(IC2);

  init_pins();
}