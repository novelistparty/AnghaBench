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
typedef  scalar_t__ uint16_t ;
struct pt_section {scalar_t__ ucount; } ;

/* Variables and functions */
 int pt_section_lock (struct pt_section*) ; 
 int pt_section_unlock (struct pt_section*) ; 
 int pte_internal ; 
 int pte_overflow ; 

int pt_section_get(struct pt_section *section)
{
	uint16_t ucount;
	int errcode;

	if (!section)
		return -pte_internal;

	errcode = pt_section_lock(section);
	if (errcode < 0)
		return errcode;

	ucount = section->ucount + 1;
	if (!ucount) {
		(void) pt_section_unlock(section);
		return -pte_overflow;
	}

	section->ucount = ucount;

	return pt_section_unlock(section);
}