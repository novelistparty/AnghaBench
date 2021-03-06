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
struct ptunit_result {int dummy; } ;
struct bcache_fixture {int /*<<< orphan*/  bcache; } ;

/* Variables and functions */
 int /*<<< orphan*/  pt_bcache_alloc (int) ; 
 struct ptunit_result ptu_passed () ; 
 int /*<<< orphan*/  ptu_ptr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct ptunit_result alloc(struct bcache_fixture *bfix)
{
	bfix->bcache = pt_bcache_alloc(0x10000ull);
	ptu_ptr(bfix->bcache);

	return ptu_passed();
}