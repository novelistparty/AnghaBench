#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int currentObject; } ;

/* Variables and functions */
 int /*<<< orphan*/  ASE_FreeGeomObject (int) ; 
 TYPE_1__ ase ; 

void ASE_Free( void ){
	int i;

	for ( i = 0; i < ase.currentObject; i++ )
	{
		ASE_FreeGeomObject( i );
	}
}