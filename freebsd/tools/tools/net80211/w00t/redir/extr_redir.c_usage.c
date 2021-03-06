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
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 

void usage(char *name)
{
	printf("Usage %s <opts>\n"
	       "-h\thelp\n"
	       "-d\t<buddy ip>\n"
	       "-p\t<port>\n"
	       "-b\t<bssid>\n"
	       "-t\t<tap>\n"
	       "-r\t<rtr>\n"
	       "-s\t<source ip>\n"
	       , name);
	exit(1);
}