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
struct agp_memory {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  amd_flush_garts () ; 

__attribute__((used)) static void amd64_tlbflush(struct agp_memory *temp)
{
	amd_flush_garts();
}