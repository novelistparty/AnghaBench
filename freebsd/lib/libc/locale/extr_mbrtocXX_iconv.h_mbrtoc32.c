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
typedef  int /*<<< orphan*/  mbstate_t ;
typedef  int /*<<< orphan*/  charXX_t ;

/* Variables and functions */
 int /*<<< orphan*/  __get_locale () ; 
 size_t mbrtocXX_l (int /*<<< orphan*/ *,char const*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

size_t
mbrtocXX(charXX_t * __restrict pc, const char * __restrict s, size_t n,
    mbstate_t * __restrict ps)
{

	return (mbrtocXX_l(pc, s, n, ps, __get_locale()));
}