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
struct ta_header {scalar_t__ canary; } ;

/* Variables and functions */
 scalar_t__ CANARY ; 
 int /*<<< orphan*/  assert (int) ; 

__attribute__((used)) static void ta_dbg_check_header(struct ta_header *h)
{
    if (h)
        assert(h->canary == CANARY);
}