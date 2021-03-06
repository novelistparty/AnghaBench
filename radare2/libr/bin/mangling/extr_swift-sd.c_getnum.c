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
 int atoi (char const*) ; 

__attribute__((used)) static const char *getnum(const char* n, int *num) {
	if (num && *n) {
		*num = atoi (n);
	}
	while (*n && *n>='0' && *n <='9') {
		n++;
	}
	return n;
}