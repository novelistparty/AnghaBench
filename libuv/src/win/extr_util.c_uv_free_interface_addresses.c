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
typedef  int /*<<< orphan*/  uv_interface_address_t ;

/* Variables and functions */
 int /*<<< orphan*/  uv__free (int /*<<< orphan*/ *) ; 

void uv_free_interface_addresses(uv_interface_address_t* addresses,
    int count) {
  uv__free(addresses);
}