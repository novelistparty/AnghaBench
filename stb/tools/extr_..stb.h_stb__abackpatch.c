#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ buffer; } ;
typedef  TYPE_1__ stbfile ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (scalar_t__,void*,unsigned int) ; 

__attribute__((used)) static void stb__abackpatch(stbfile *f, unsigned int where, void *data, unsigned int len)
{
   memcpy(f->buffer+where, data, len);
}