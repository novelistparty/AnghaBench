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
typedef  scalar_t__ uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  cur_csum ; 
 int /*<<< orphan*/  send_data (scalar_t__ const*,size_t) ; 

__attribute__((used)) static void
append_packet_data(const uint8_t *data, size_t len)
{

	send_data(data, len);
	while (len > 0) {
		cur_csum += *data;
		data++;
		len--;
	}
}