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
struct afswtch {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  domediaopt (char const*,int,int) ; 

__attribute__((used)) static void
unsetmediaopt(const char *val, int d, int s, const struct afswtch *afp)
{

	domediaopt(val, 1, s);
}