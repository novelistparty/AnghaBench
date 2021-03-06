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
typedef  int /*<<< orphan*/  BN_ULONG ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  sqr64 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  const) ; 

void bn_sqr_words(BN_ULONG *r, const BN_ULONG *a, int n)
{
    assert(n >= 0);
    if (n <= 0)
        return;

# ifndef OPENSSL_SMALL_FOOTPRINT
    while (n & ~3) {
        sqr64(r[0], r[1], a[0]);
        sqr64(r[2], r[3], a[1]);
        sqr64(r[4], r[5], a[2]);
        sqr64(r[6], r[7], a[3]);
        a += 4;
        r += 8;
        n -= 4;
    }
# endif
    while (n) {
        sqr64(r[0], r[1], a[0]);
        a++;
        r += 2;
        n--;
    }
}