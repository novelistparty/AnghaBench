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
struct hist_entry {scalar_t__ srcfile; } ;

/* Variables and functions */
 scalar_t__ hist_entry__get_srcfile (struct hist_entry*) ; 
 int repsep_snprintf (char*,size_t,char*,unsigned int,scalar_t__) ; 

__attribute__((used)) static int hist_entry__srcfile_snprintf(struct hist_entry *he, char *bf,
					size_t size, unsigned int width)
{
	if (!he->srcfile)
		he->srcfile = hist_entry__get_srcfile(he);

	return repsep_snprintf(bf, size, "%-.*s", width, he->srcfile);
}