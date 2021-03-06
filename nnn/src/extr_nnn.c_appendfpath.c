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
 scalar_t__ PATH_MAX ; 
 int /*<<< orphan*/  errexit () ; 
 scalar_t__ pselbuf ; 
 scalar_t__ selbuflen ; 
 scalar_t__ selbufpos ; 
 scalar_t__ xrealloc (scalar_t__,scalar_t__) ; 
 scalar_t__ xstrlcpy (scalar_t__,char const*,size_t const) ; 

__attribute__((used)) static void appendfpath(const char *path, const size_t len)
{
	if ((selbufpos >= selbuflen) || ((len + 3) > (selbuflen - selbufpos))) {
		selbuflen += PATH_MAX;
		pselbuf = xrealloc(pselbuf, selbuflen);
		if (!pselbuf)
			errexit();
	}

	selbufpos += xstrlcpy(pselbuf + selbufpos, path, len);
}