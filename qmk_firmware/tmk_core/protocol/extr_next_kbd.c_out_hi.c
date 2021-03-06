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
 int NEXT_KBD_OUT_BIT ; 
 int NEXT_KBD_OUT_DDR ; 
 int NEXT_KBD_OUT_PORT ; 

__attribute__((used)) static inline void out_hi(void) {
    /* input with pull up */
    NEXT_KBD_OUT_DDR &= ~(1 << NEXT_KBD_OUT_BIT);
    NEXT_KBD_OUT_PORT |= (1 << NEXT_KBD_OUT_BIT);
}