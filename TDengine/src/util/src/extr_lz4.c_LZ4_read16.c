#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  u16; } ;
typedef  TYPE_1__ unalign ;
typedef  int /*<<< orphan*/  U16 ;

/* Variables and functions */

__attribute__((used)) static U16 LZ4_read16(const void* ptr) { return ((const unalign*)ptr)->u16; }