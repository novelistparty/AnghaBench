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
struct state {struct arc* outs; } ;
struct arc {struct arc* outchain; } ;

/* Variables and functions */
 scalar_t__ isconstraintarc (struct arc*) ; 

__attribute__((used)) static int
hasconstraintout(struct state *s)
{
	struct arc *a;

	for (a = s->outs; a != NULL; a = a->outchain)
	{
		if (isconstraintarc(a))
			return 1;
	}
	return 0;
}