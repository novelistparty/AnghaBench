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
typedef  int /*<<< orphan*/  wchar_t ;
struct archive_entry {int ae_set; int /*<<< orphan*/  ae_symlink; int /*<<< orphan*/  archive; } ;

/* Variables and functions */
 int AE_SET_SYMLINK ; 
 scalar_t__ ENOMEM ; 
 int /*<<< orphan*/  __archive_errx (int,char*) ; 
 scalar_t__ archive_mstring_get_wcs (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  const**) ; 
 scalar_t__ errno ; 

const wchar_t *
archive_entry_symlink_w(struct archive_entry *entry)
{
	const wchar_t *p;
	if ((entry->ae_set & AE_SET_SYMLINK) == 0)
		return (NULL);
	if (archive_mstring_get_wcs(
	    entry->archive, &entry->ae_symlink, &p) == 0)
		return (p);
	if (errno == ENOMEM)
		__archive_errx(1, "No memory");
	return (NULL);
}