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
typedef  int /*<<< orphan*/  RFlagItem ;

/* Variables and functions */
 int /*<<< orphan*/  r_list_append (void*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static bool listFlag(RFlagItem *flag, void *user) {
	r_list_append (user, flag);
	return true;
}