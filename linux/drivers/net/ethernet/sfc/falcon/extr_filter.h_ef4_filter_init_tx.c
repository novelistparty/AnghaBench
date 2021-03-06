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
struct ef4_filter_spec {unsigned int dmaq_id; int /*<<< orphan*/  flags; int /*<<< orphan*/  priority; } ;

/* Variables and functions */
 int /*<<< orphan*/  EF4_FILTER_FLAG_TX ; 
 int /*<<< orphan*/  EF4_FILTER_PRI_REQUIRED ; 
 int /*<<< orphan*/  memset (struct ef4_filter_spec*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void ef4_filter_init_tx(struct ef4_filter_spec *spec,
				      unsigned txq_id)
{
	memset(spec, 0, sizeof(*spec));
	spec->priority = EF4_FILTER_PRI_REQUIRED;
	spec->flags = EF4_FILTER_FLAG_TX;
	spec->dmaq_id = txq_id;
}