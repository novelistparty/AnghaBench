#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ Flink; } ;
struct TYPE_5__ {scalar_t__ Flink; } ;
struct TYPE_6__ {TYPE_1__ navigator; } ;
typedef  TYPE_2__* PKUHL_M_DPAPI_OE_CREDENTIAL_ENTRY ;

/* Variables and functions */
 TYPE_4__ gDPAPI_Credentials ; 
 int /*<<< orphan*/  kuhl_m_dpapi_oe_credential_descr (TYPE_2__*) ; 

void kuhl_m_dpapi_oe_credentials_descr()
{
	PKUHL_M_DPAPI_OE_CREDENTIAL_ENTRY entry;
	for(entry = (PKUHL_M_DPAPI_OE_CREDENTIAL_ENTRY) gDPAPI_Credentials.Flink; entry != (PKUHL_M_DPAPI_OE_CREDENTIAL_ENTRY) &gDPAPI_Credentials; entry = (PKUHL_M_DPAPI_OE_CREDENTIAL_ENTRY) entry->navigator.Flink)
		kuhl_m_dpapi_oe_credential_descr(entry);
}