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
 int indexed ; 
 int indx (char const**,char const**,int,int /*<<< orphan*/ *) ; 
 int ld_nnHL ; 

__attribute__((used)) static int rd_ld_nn(const char **p) {
#define ld_nnHL 5
#define ld_nnA 6
	int i;
	const char *list[] = {
		"bc", "de", "", "sp", "hl", "a", "ix", "iy", NULL
	};
	i = indx (p, list, 1, NULL);
	if (i < 7) {
		return i;
	}
	indexed = 0xdd + 0x20 * (i == 8);
	return ld_nnHL;
}