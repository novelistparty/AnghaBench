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
typedef  int /*<<< orphan*/  mpg123_picture ;

/* Variables and functions */
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_mpg123_picture (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * safe_realloc (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void pop_id3_picture(mpg123_picture **list, size_t *size)
{
	mpg123_picture *x;
	if(*size < 1) return;

	free_mpg123_picture(&((*list)[*size-1]));
	if(*size > 1)
	{
		x = safe_realloc(*list, sizeof(mpg123_picture)*(*size-1));
		if(x != NULL){ *list  = x; *size -= 1; }
	}
	else
	{
		free(*list);
		*list = NULL;
		*size = 0;
	}
}