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
struct hidpad_ps2adapter_data {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct hidpad_ps2adapter_data*) ; 

__attribute__((used)) static void hidpad_ps2adapter_deinit(void *data)
{
   struct hidpad_ps2adapter_data *device = (struct hidpad_ps2adapter_data*)data;

   if (device)
      free(device);
}