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
typedef  int /*<<< orphan*/  blake2b_state ;
typedef  int /*<<< orphan*/  blake2b_param ;

/* Variables and functions */
 int blake2b_init_param_ptr (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

int blake2b_init_param( blake2b_state *S, const blake2b_param *P )
{
  return blake2b_init_param_ptr( S, P );
}