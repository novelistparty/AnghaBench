#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ tei_entity; } ;
typedef  TYPE_1__ TDIEntityID ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ CL_NL_ENTITY ; 
 scalar_t__ CO_NL_ENTITY ; 

BOOL isIpEntity( HANDLE tcpFile, TDIEntityID *ent ) {
    return (ent->tei_entity == CL_NL_ENTITY ||
            ent->tei_entity == CO_NL_ENTITY);
}