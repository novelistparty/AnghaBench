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
typedef  int /*<<< orphan*/  lsn_t ;
typedef  int /*<<< orphan*/  iso9660_t ;
typedef  int /*<<< orphan*/  iso9660_stat_t ;
typedef  int /*<<< orphan*/  iso9660_readdir_t ;

/* Variables and functions */
 int /*<<< orphan*/ * find_lsn_recurse (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char**) ; 
 int /*<<< orphan*/  free (char*) ; 
 scalar_t__ iso9660_ifs_readdir ; 

iso9660_stat_t *
iso9660_ifs_find_lsn(iso9660_t *p_iso, lsn_t i_lsn)
{
  char *psz_full_filename = NULL;
  iso9660_stat_t *ret  =
    find_lsn_recurse (p_iso, (iso9660_readdir_t *) iso9660_ifs_readdir,
		      "/", i_lsn, &psz_full_filename);
  if (psz_full_filename != NULL)
    free(psz_full_filename);
  return ret;
}