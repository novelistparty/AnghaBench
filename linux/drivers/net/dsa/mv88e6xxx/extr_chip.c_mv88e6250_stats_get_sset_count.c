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
struct mv88e6xxx_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  STATS_TYPE_BANK0 ; 
 int mv88e6xxx_stats_get_sset_count (struct mv88e6xxx_chip*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int mv88e6250_stats_get_sset_count(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_stats_get_sset_count(chip, STATS_TYPE_BANK0);
}