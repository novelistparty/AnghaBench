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

/* Variables and functions */
 int /*<<< orphan*/  create_all_outbound_connections () ; 
 int /*<<< orphan*/  spell_reoder_spellers () ; 

void cron (void) {
  create_all_outbound_connections ();
  spell_reoder_spellers ();
}