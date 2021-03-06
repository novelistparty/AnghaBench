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
struct unwind_state {int dummy; } ;

/* Variables and functions */
 unsigned long* GCC_REALIGN_WORDS ; 
 unsigned long* last_frame (struct unwind_state*) ; 

__attribute__((used)) static inline unsigned long *last_aligned_frame(struct unwind_state *state)
{
	return last_frame(state) - GCC_REALIGN_WORDS;
}