#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  origin; } ;
struct TYPE_6__ {TYPE_1__ s; } ;
typedef  TYPE_2__ gentity_t ;

/* Variables and functions */
 int /*<<< orphan*/  G_SetOrigin (TYPE_2__*,int /*<<< orphan*/ ) ; 

void SP_info_camp( gentity_t *self ) {
	G_SetOrigin( self, self->s.origin );
}