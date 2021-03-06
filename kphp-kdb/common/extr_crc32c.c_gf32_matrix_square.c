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
 unsigned int gf32_matrix_times (unsigned int*,unsigned int) ; 

__attribute__((used)) static void gf32_matrix_square (unsigned *square, unsigned *matrix) {
  int n = 0;
  do {
    square[n] = gf32_matrix_times (matrix, matrix[n]);
  } while (++n < 32);
}