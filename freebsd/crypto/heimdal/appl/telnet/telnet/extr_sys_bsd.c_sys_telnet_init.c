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
 int /*<<< orphan*/  NetNonblockingIO (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SIGINFO ; 
 int /*<<< orphan*/  SIGINT ; 
 int /*<<< orphan*/  SIGPIPE ; 
 int /*<<< orphan*/  SIGQUIT ; 
 int /*<<< orphan*/  SIGTSTP ; 
 int /*<<< orphan*/  SIGWINCH ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_OOBINLINE ; 
 int SetSockOpt (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ayt ; 
 int /*<<< orphan*/  deadpeer ; 
 int /*<<< orphan*/  intr ; 
 int /*<<< orphan*/  intr2 ; 
 int /*<<< orphan*/  net ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  sendwin ; 
 int /*<<< orphan*/  setconnmode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  susp ; 

void
sys_telnet_init(void)
{
    signal(SIGINT, intr);
    signal(SIGQUIT, intr2);
    signal(SIGPIPE, deadpeer);
#ifdef	SIGWINCH
    signal(SIGWINCH, sendwin);
#endif
#ifdef	SIGTSTP
    signal(SIGTSTP, susp);
#endif
#ifdef	SIGINFO
    signal(SIGINFO, ayt);
#endif

    setconnmode(0);

    NetNonblockingIO(net, 1);


#if	defined(SO_OOBINLINE)
    if (SetSockOpt(net, SOL_SOCKET, SO_OOBINLINE, 1) == -1)
	perror("setsockopt (SO_OOBINLINE) (ignored)");
#endif	/* defined(SO_OOBINLINE) */
}