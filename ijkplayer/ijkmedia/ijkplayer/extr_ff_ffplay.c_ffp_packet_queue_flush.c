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
typedef  int /*<<< orphan*/  PacketQueue ;

/* Variables and functions */
 void packet_queue_flush (int /*<<< orphan*/ *) ; 

void ffp_packet_queue_flush(PacketQueue *q)
{
    return packet_queue_flush(q);
}