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
typedef  int /*<<< orphan*/  vfs_entry_t ;
struct _reent {int dummy; } ;
typedef  int /*<<< orphan*/  __errno_r ;

/* Variables and functions */
 int /*<<< orphan*/  CHECK_AND_CALL (int,struct _reent*,int /*<<< orphan*/  const*,int (*) (char const*,int),char const*,int) ; 
 int /*<<< orphan*/  ENOENT ; 
 struct _reent* __getreent () ; 
 int /*<<< orphan*/ * get_vfs_for_path (char const*) ; 
 char* translate_path (int /*<<< orphan*/  const*,char const*) ; 

int access(const char *path, int amode)
{
    int ret;
    const vfs_entry_t* vfs = get_vfs_for_path(path);
    struct _reent* r = __getreent();
    if (vfs == NULL) {
        __errno_r(r) = ENOENT;
        return -1;
    }
    const char* path_within_vfs = translate_path(vfs, path);
    CHECK_AND_CALL(ret, r, vfs, access, path_within_vfs, amode);
    return ret;
}