#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int len; int sym; } ;
typedef  TYPE_1__ HuffEntry ;

/* Variables and functions */

__attribute__((used)) static int huff_cmp_len12(const void *a, const void *b)
{
    const HuffEntry *aa = a, *bb = b;
    return (aa->len - bb->len) * 4096 + aa->sym - bb->sym;
}