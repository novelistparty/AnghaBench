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
typedef  int /*<<< orphan*/  byte_t ;
typedef  scalar_t__ addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  pt_write8 (int,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  user_get (scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void pt_copy(int pid, addr_t start, size_t size) {
    if (start == 0)
        return;
    byte_t byte;
    for (addr_t addr = start; addr < start + size; addr++) {
        (void) user_get(addr, byte);
        pt_write8(pid, addr, byte);
    }
}