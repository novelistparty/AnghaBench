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
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_2__ {char const* name; } ;

/* Variables and functions */
 TYPE_1__* cmd_status ; 
 int ibmvfc_get_err_index (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char const* unknown_error ; 

__attribute__((used)) static const char *ibmvfc_get_cmd_error(u16 status, u16 error)
{
	int rc = ibmvfc_get_err_index(status, error);
	if (rc >= 0)
		return cmd_status[rc].name;
	return unknown_error;
}