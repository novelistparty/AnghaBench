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
struct fetch_fixture {int /*<<< orphan*/  encoder; } ;

/* Variables and functions */
 int /*<<< orphan*/  pt_encoder_fini (int /*<<< orphan*/ *) ; 
 struct ptunit_result ptu_passed () ; 

__attribute__((used)) static struct ptunit_result ffix_fini(struct fetch_fixture *ffix)
{
	pt_encoder_fini(&ffix->encoder);

	return ptu_passed();
}