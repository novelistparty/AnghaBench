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
 char get_hex_char (int) ; 

__attribute__((used)) static void format_hex(char *buf, int val) {
    buf[0] = get_hex_char(val >> 4);
    buf[1] = get_hex_char(val);
}