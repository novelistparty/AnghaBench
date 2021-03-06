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
typedef  int /*<<< orphan*/  pid_t ;

/* Variables and functions */
 int /*<<< orphan*/  SYS_kill ; 
 int errno ; 
 int syscall2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

int kill( pid_t pid, int signal ) {
    int error;

    error = syscall2(
        SYS_kill,
        pid,
        signal
    );

    if ( error < 0 ) {
        errno = -error;
        return -1;
    }

    return 0;
}