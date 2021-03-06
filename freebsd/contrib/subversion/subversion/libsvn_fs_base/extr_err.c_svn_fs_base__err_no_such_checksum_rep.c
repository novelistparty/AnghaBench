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
struct TYPE_3__ {int /*<<< orphan*/  path; int /*<<< orphan*/  pool; } ;
typedef  TYPE_1__ svn_fs_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_checksum_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR_FS_NO_SUCH_CHECKSUM_REP ; 
 int /*<<< orphan*/  _ (char*) ; 
 int /*<<< orphan*/  svn_checksum_to_cstring_display (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * svn_error_createf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

svn_error_t *
svn_fs_base__err_no_such_checksum_rep(svn_fs_t *fs, svn_checksum_t *checksum)
{
  return
    svn_error_createf
    (SVN_ERR_FS_NO_SUCH_CHECKSUM_REP, 0,
     _("No record in 'checksum-reps' table for checksum '%s' in "
       "filesystem '%s'"), svn_checksum_to_cstring_display(checksum,
                                                           fs->pool),
                           fs->path);
}