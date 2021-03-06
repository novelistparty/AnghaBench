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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int /*<<< orphan*/  NTSTATUS ;

/* Variables and functions */
 int /*<<< orphan*/  PRINT_ERROR (char*) ; 
 int /*<<< orphan*/  STATUS_SUCCESS ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ isBusyLight ; 
 int /*<<< orphan*/  kuhl_m_busylight_devices ; 
 int /*<<< orphan*/  kull_m_busylight_request_send_off (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

NTSTATUS kuhl_m_busylight_off(int argc, wchar_t * argv[])
{
	if(isBusyLight)
		kull_m_busylight_request_send_off(kuhl_m_busylight_devices, TRUE);
	else PRINT_ERROR(L"No BusyLight\n");
	return STATUS_SUCCESS;
}