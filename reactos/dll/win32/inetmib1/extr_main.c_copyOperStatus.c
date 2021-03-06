#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/  number; } ;
struct TYPE_5__ {TYPE_1__ asnValue; int /*<<< orphan*/  asnType; } ;
typedef  int DWORD ;
typedef  TYPE_2__ AsnAny ;

/* Variables and functions */
 int /*<<< orphan*/  ASN_INTEGER ; 
 int /*<<< orphan*/  MIB_IF_ADMIN_STATUS_DOWN ; 
 int /*<<< orphan*/  MIB_IF_ADMIN_STATUS_TESTING ; 
 int /*<<< orphan*/  MIB_IF_ADMIN_STATUS_UP ; 
#define  MIB_IF_OPER_STATUS_CONNECTED 130 
#define  MIB_IF_OPER_STATUS_CONNECTING 129 
#define  MIB_IF_OPER_STATUS_OPERATIONAL 128 
 int SNMP_ERRORSTATUS_NOERROR ; 

__attribute__((used)) static DWORD copyOperStatus(AsnAny *value, void *src)
{
    value->asnType = ASN_INTEGER;
    /* The IPHlpApi definition of operational status differs from the MIB2 one,
     * so map it to the MIB2 value.
     */
    switch (*(DWORD *)src)
    {
    case MIB_IF_OPER_STATUS_OPERATIONAL:
        value->asnValue.number = MIB_IF_ADMIN_STATUS_UP;
        break;
    case MIB_IF_OPER_STATUS_CONNECTING:
    case MIB_IF_OPER_STATUS_CONNECTED:
        value->asnValue.number = MIB_IF_ADMIN_STATUS_TESTING;
        break;
    default:
        value->asnValue.number = MIB_IF_ADMIN_STATUS_DOWN;
    };
    return SNMP_ERRORSTATUS_NOERROR;
}