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
typedef  int /*<<< orphan*/  FICL_VM ;

/* Variables and functions */
 int /*<<< orphan*/  VM_QUIT ; 
 int /*<<< orphan*/  vmThrow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void quit(FICL_VM *pVM)
{
    vmThrow(pVM, VM_QUIT);
    return;
}