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
typedef  int /*<<< orphan*/  WCHAR ;

/* Variables and functions */
 int /*<<< orphan*/ * heap_alloc (int) ; 
 int /*<<< orphan*/  wcscpy (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int wcslen (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static WCHAR *heap_strdupW(const WCHAR *str)
{
    int len = wcslen(str) + 1;
    WCHAR *ret = heap_alloc(len * sizeof(WCHAR));
    wcscpy(ret, str);
    return ret;
}