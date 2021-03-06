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
typedef  int /*<<< orphan*/  vlc_interrupt_t ;

/* Variables and functions */
 int /*<<< orphan*/  test_context_simple (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vlc_interrupt_set (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void *test_thread_cleanup(void *data)
{
    vlc_interrupt_t *ctx = data;

    test_context_simple(ctx);
    /* Test context clearing on exit */
    vlc_interrupt_set(ctx);
    return NULL;
}