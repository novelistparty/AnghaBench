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
typedef  int u16 ;
struct komeda_component_state {int changed_active_inputs; } ;

/* Variables and functions */
 int component_disabling_inputs (struct komeda_component_state*) ; 

__attribute__((used)) static inline u16 component_changed_inputs(struct komeda_component_state *st)
{
	return component_disabling_inputs(st) | st->changed_active_inputs;
}