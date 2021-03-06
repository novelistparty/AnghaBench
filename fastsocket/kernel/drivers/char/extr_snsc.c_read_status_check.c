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
struct subch_data_s {int /*<<< orphan*/  sd_rb; int /*<<< orphan*/  sd_subch; int /*<<< orphan*/  sd_nasid; } ;

/* Variables and functions */
 int ia64_sn_irtr_recv (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 

__attribute__((used)) static inline int
read_status_check(struct subch_data_s *sd, int *len)
{
	return ia64_sn_irtr_recv(sd->sd_nasid, sd->sd_subch, sd->sd_rb, len);
}