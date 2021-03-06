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
struct smbfns {int id; scalar_t__ name; } ;

/* Variables and functions */

__attribute__((used)) static const struct smbfns *
smbfind(int id, const struct smbfns *list)
{
    int sindex;

    for (sindex = 0; list[sindex].name; sindex++)
	if (list[sindex].id == id)
	    return(&list[sindex]);

    return(&list[0]);
}