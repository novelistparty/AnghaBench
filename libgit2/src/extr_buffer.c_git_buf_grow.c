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
typedef  int /*<<< orphan*/  git_buf ;

/* Variables and functions */
 int git_buf_try_grow (int /*<<< orphan*/ *,size_t,int) ; 

int git_buf_grow(git_buf *buffer, size_t target_size)
{
	return git_buf_try_grow(buffer, target_size, true);
}