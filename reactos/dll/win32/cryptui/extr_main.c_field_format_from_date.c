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
typedef  int /*<<< orphan*/  WCHAR ;
struct TYPE_5__ {TYPE_1__* pCertInfo; } ;
struct TYPE_4__ {int /*<<< orphan*/  NotBefore; } ;
typedef  TYPE_2__* PCCERT_CONTEXT ;

/* Variables and functions */
 int /*<<< orphan*/ * format_long_date (int /*<<< orphan*/ *) ; 

__attribute__((used)) static WCHAR *field_format_from_date(PCCERT_CONTEXT cert)
{
    return format_long_date(&cert->pCertInfo->NotBefore);
}