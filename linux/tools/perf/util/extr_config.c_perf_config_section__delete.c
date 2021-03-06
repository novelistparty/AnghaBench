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
struct perf_config_section {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct perf_config_section*) ; 
 int /*<<< orphan*/  perf_config_section__purge (struct perf_config_section*) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void perf_config_section__delete(struct perf_config_section *section)
{
	perf_config_section__purge(section);
	zfree(&section->name);
	free(section);
}