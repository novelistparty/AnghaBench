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
struct iovec {char* iov_base; int /*<<< orphan*/  iov_len; } ;

/* Variables and functions */
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bcopy (char const*,char*,size_t) ; 
 size_t min (size_t,int /*<<< orphan*/ ) ; 

void
xh_vm_copyin(struct iovec *iov, void *dst, size_t len)
{
	const char *src;
	char *d;
	size_t n;

	d = dst;
	while (len) {
		assert(iov->iov_len);
		n = min(len, iov->iov_len);
		src = iov->iov_base;
		bcopy(src, d, n);
		iov++;
		d += n;
		len -= n;
	}
}