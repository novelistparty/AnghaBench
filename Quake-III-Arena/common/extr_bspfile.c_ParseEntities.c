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

/* Variables and functions */
 scalar_t__ ParseEntity () ; 
 int /*<<< orphan*/  ParseFromMemory (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dentdata ; 
 int /*<<< orphan*/  entdatasize ; 
 scalar_t__ num_entities ; 

void ParseEntities( void ) {
	num_entities = 0;
	ParseFromMemory( dentdata, entdatasize );

	while ( ParseEntity () ) {
	}	
}