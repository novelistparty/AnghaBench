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
typedef  int u8 ;
struct dvb_usb_rc_key {int scan; } ;

/* Variables and functions */

__attribute__((used)) static inline u8 rc5_scan(struct dvb_usb_rc_key *key)
{
	return key->scan & 0xffff;
}