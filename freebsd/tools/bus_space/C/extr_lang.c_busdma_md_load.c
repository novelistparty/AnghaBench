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
typedef  int /*<<< orphan*/  u_int ;
typedef  int /*<<< orphan*/  busdma_md_t ;

/* Variables and functions */
 int bd_md_load (int /*<<< orphan*/ ,void*,size_t,int /*<<< orphan*/ ) ; 

int
busdma_md_load(busdma_md_t md, void *buf, size_t len, u_int flags)
{

	return (bd_md_load(md, buf, len, flags));
}