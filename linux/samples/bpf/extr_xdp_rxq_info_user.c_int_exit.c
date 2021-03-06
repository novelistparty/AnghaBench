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
typedef  scalar_t__ __u32 ;

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAIL ; 
 int /*<<< orphan*/  EXIT_OK ; 
 scalar_t__ bpf_get_link_xdp_id (int,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bpf_set_link_xdp_fd (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,char*) ; 
 int ifindex ; 
 char* ifname ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ prog_id ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  xdp_flags ; 

__attribute__((used)) static void int_exit(int sig)
{
	__u32 curr_prog_id = 0;

	if (ifindex > -1) {
		if (bpf_get_link_xdp_id(ifindex, &curr_prog_id, xdp_flags)) {
			printf("bpf_get_link_xdp_id failed\n");
			exit(EXIT_FAIL);
		}
		if (prog_id == curr_prog_id) {
			fprintf(stderr,
				"Interrupted: Removing XDP program on ifindex:%d device:%s\n",
				ifindex, ifname);
			bpf_set_link_xdp_fd(ifindex, -1, xdp_flags);
		} else if (!curr_prog_id) {
			printf("couldn't find a prog id on a given iface\n");
		} else {
			printf("program on interface changed, not removing\n");
		}
	}
	exit(EXIT_OK);
}