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
struct radius_msg {struct radius_hdr* hdr; } ;
struct radius_hdr {int dummy; } ;

/* Variables and functions */

struct radius_hdr * radius_msg_get_hdr(struct radius_msg *msg)
{
	return msg->hdr;
}