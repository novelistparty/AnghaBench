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
struct inpcb {int dummy; } ;

/* Variables and functions */
 int in_pcbinshash_internal (struct inpcb*,int /*<<< orphan*/ ) ; 

int
in_pcbinshash_nopcbgroup(struct inpcb *inp)
{

	return (in_pcbinshash_internal(inp, 0));
}