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
typedef  int /*<<< orphan*/  u64 ;
struct clocksource {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  cs_to_em_sti (struct clocksource*) ; 
 int /*<<< orphan*/  em_sti_count (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u64 em_sti_clocksource_read(struct clocksource *cs)
{
	return em_sti_count(cs_to_em_sti(cs));
}