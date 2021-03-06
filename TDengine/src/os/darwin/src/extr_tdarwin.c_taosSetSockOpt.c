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
typedef  int /*<<< orphan*/  socklen_t ;

/* Variables and functions */
 int SOL_SOCKET ; 
 int SO_RCVBUF ; 
 int SO_SNDBUF ; 
 int setsockopt (int,int,int,void*,int /*<<< orphan*/ ) ; 

int taosSetSockOpt(int socketfd, int level, int optname, void *optval, int optlen) {
  if (level == SOL_SOCKET && optname == SO_SNDBUF) {
    return 0;
  }

  if (level == SOL_SOCKET && optname == SO_RCVBUF) {
    return 0;
  }

  return setsockopt(socketfd, level, optname, optval, (socklen_t)optlen);
}