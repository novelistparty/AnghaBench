#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {scalar_t__ oid; } ;
struct TYPE_13__ {void* dump; TYPE_1__ catId; } ;
struct TYPE_12__ {TYPE_7__ dobj; } ;
struct TYPE_11__ {TYPE_2__* dopt; } ;
struct TYPE_10__ {scalar_t__ include_everything; } ;
typedef  scalar_t__ Oid ;
typedef  TYPE_3__ Archive ;
typedef  TYPE_4__ AccessMethodInfo ;

/* Variables and functions */
 void* DUMP_COMPONENT_ALL ; 
 void* DUMP_COMPONENT_NONE ; 
 scalar_t__ checkExtensionMembership (TYPE_7__*,TYPE_3__*) ; 
 scalar_t__ g_last_builtin_oid ; 

__attribute__((used)) static void
selectDumpableAccessMethod(AccessMethodInfo *method, Archive *fout)
{
	if (checkExtensionMembership(&method->dobj, fout))
		return;					/* extension membership overrides all else */

	/*
	 * This would be DUMP_COMPONENT_ACL for from-initdb access methods, but
	 * they do not support ACLs currently.
	 */
	if (method->dobj.catId.oid <= (Oid) g_last_builtin_oid)
		method->dobj.dump = DUMP_COMPONENT_NONE;
	else
		method->dobj.dump = fout->dopt->include_everything ?
			DUMP_COMPONENT_ALL : DUMP_COMPONENT_NONE;
}