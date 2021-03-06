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
 int /*<<< orphan*/  err (int,char*,size_t) ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/  memmove (void*,void*,size_t) ; 

__attribute__((used)) static void *
xcopy(void *text, size_t len)
{
	void *p;

	if ((p = malloc(len)) == NULL)
		err(1, "Cannot allocate %zu bytes", len);
	(void)memmove(p, text, len);
	return p;
}