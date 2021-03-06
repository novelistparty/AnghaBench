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
typedef  int int32_t ;
typedef  scalar_t__ VCHI_INSTANCE_T ;
typedef  scalar_t__ VCHIQ_STATUS_T ;
typedef  int /*<<< orphan*/  VCHIQ_INSTANCE_T ;

/* Variables and functions */
 scalar_t__ VCHIQ_SUCCESS ; 
 scalar_t__ vchiq_shutdown (int /*<<< orphan*/ ) ; 

int32_t
vchi_disconnect( VCHI_INSTANCE_T instance_handle )
{
   VCHIQ_STATUS_T status;

   status = vchiq_shutdown((VCHIQ_INSTANCE_T)instance_handle);

   return (status == VCHIQ_SUCCESS) ? 0 : -1;
}