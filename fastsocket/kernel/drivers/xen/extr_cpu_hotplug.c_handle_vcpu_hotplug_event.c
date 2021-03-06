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
struct xenbus_watch {int dummy; } ;

/* Variables and functions */
 size_t XS_WATCH_PATH ; 
 int /*<<< orphan*/  sscanf (char*,char*,unsigned int*) ; 
 char* strstr (char const*,char*) ; 
 int /*<<< orphan*/  vcpu_hotplug (unsigned int) ; 

__attribute__((used)) static void handle_vcpu_hotplug_event(struct xenbus_watch *watch,
					const char **vec, unsigned int len)
{
	unsigned int cpu;
	char *cpustr;
	const char *node = vec[XS_WATCH_PATH];

	cpustr = strstr(node, "cpu/");
	if (cpustr != NULL) {
		sscanf(cpustr, "cpu/%u", &cpu);
		vcpu_hotplug(cpu);
	}
}