#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct fd {int dummy; } ;
typedef  int /*<<< orphan*/  path ;
typedef  int /*<<< orphan*/  dword_t ;
typedef  int /*<<< orphan*/  addr_t ;
struct TYPE_4__ {TYPE_1__* fs; } ;
struct TYPE_3__ {int /*<<< orphan*/  lock; struct fd* root; } ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct fd*) ; 
 int MAX_PATH ; 
 int /*<<< orphan*/  PTR_ERR (struct fd*) ; 
 int /*<<< orphan*/  STRACE (char*,char*) ; 
 int /*<<< orphan*/  _EFAULT ; 
 TYPE_2__* current ; 
 int /*<<< orphan*/  fd_close (struct fd*) ; 
 int /*<<< orphan*/  lock (int /*<<< orphan*/ *) ; 
 struct fd* open_dir (char*) ; 
 int /*<<< orphan*/  unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ user_read_string (int /*<<< orphan*/ ,char*,int) ; 

dword_t sys_chroot(addr_t path_addr) {
    char path[MAX_PATH];
    if (user_read_string(path_addr, path, sizeof(path)))
        return _EFAULT;
    STRACE("chroot(\"%s\")", path);

    struct fd *dir = open_dir(path);
    if (IS_ERR(dir))
        return PTR_ERR(dir);
    lock(&current->fs->lock);
    fd_close(current->fs->root);
    current->fs->root = dir;
    unlock(&current->fs->lock);
    return 0;
}