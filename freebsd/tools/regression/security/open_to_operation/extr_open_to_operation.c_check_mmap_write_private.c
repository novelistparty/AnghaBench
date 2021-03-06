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

/* Variables and functions */
 char* MAP_FAILED ; 
 int /*<<< orphan*/  MAP_PRIVATE ; 
 int O_ACCMODE ; 
 int O_RDONLY ; 
 int O_RDWR ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  getpagesize () ; 
 char* mmap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  notok_mode (char const*,char*,int) ; 
 int /*<<< orphan*/  ok_mode (char const*,char*,int) ; 
 int open (char const*,int) ; 

__attribute__((used)) static void
check_mmap_write_private(const char *testname, const char *path, int isdir,
    const int *modes, int modes_count)
{
	int fd, i, mode;
	char *addr;

	/*
	 * mmap() write private should succeed for readable descriptors
	 * except for directories.
	 */
	for (i = 0; i < modes_count; i++) {
		mode = modes[i];
		fd = open(path, mode);
		if (fd < 0) {
			notok_mode(testname, "open", mode);
			continue;
		}
		addr = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE,
		    MAP_PRIVATE, fd, 0);
		if (addr == MAP_FAILED) {
			if (isdir)
				ok_mode(testname, "mmap dir failed", mode);
			else if ((mode & O_ACCMODE) == O_RDONLY ||
			    (mode & O_ACCMODE) == O_RDWR)
				notok_mode(testname, "mmap file failed",
				    mode);
			else
				ok_mode(testname, "mmap file failed", mode);
		} else {
			if (isdir)
				notok_mode(testname, "mmap dir succeeded",
				    mode);
			else if ((mode & O_ACCMODE) == O_RDONLY ||
			    (mode & O_ACCMODE) == O_RDWR)
				ok_mode(testname, "mmap file succeeded",
				    mode);
			else
				notok_mode(testname, "mmap file succeeded",
				    mode);
			(void)munmap(addr, getpagesize());
		}
		close(fd);
	}
}