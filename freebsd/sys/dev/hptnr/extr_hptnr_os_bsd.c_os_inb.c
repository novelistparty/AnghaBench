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
typedef  scalar_t__ HPT_UPTR ;
typedef  int /*<<< orphan*/  HPT_U8 ;

/* Variables and functions */
 int /*<<< orphan*/  inb (unsigned int) ; 

HPT_U8   os_inb  (void *port) { return inb((unsigned)(HPT_UPTR)port); }