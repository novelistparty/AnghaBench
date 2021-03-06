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
struct int_queue {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  cbuf_init (struct int_queue*) ; 
 int /*<<< orphan*/  cbuf_is_full (struct int_queue*) ; 
 int cbuf_push (struct int_queue*,int) ; 
 int cbuf_take (struct int_queue*,int*) ; 

__attribute__((used)) static void test_cbuf_full(void) {
    struct int_queue queue;
    cbuf_init(&queue);

    assert(!cbuf_is_full(&queue));

    // fill the queue
    for (int i = 0; i < 32; ++i) {
        bool ok = cbuf_push(&queue, i);
        assert(ok);
    }
    bool ok = cbuf_push(&queue, 42);
    assert(!ok); // the queue if full

    int item;
    bool take_ok = cbuf_take(&queue, &item);
    assert(take_ok);
    assert(!cbuf_is_full(&queue));
}