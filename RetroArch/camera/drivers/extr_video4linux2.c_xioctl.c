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
 scalar_t__ EINTR ; 
 scalar_t__ errno ; 
 int ioctl (int,unsigned long,void*) ; 

__attribute__((used)) static int xioctl(int fd, unsigned long request, void *args)
{
   int r;

   do
   {
      r = ioctl(fd, request, args);
   } while (r == -1 && errno == EINTR);

   return r;
}