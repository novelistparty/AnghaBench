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
typedef  int /*<<< orphan*/  retro_input_poll_t ;

/* Variables and functions */
 int /*<<< orphan*/  input_poll_cb ; 

void retro_set_input_poll(retro_input_poll_t cb) { input_poll_cb = cb; }