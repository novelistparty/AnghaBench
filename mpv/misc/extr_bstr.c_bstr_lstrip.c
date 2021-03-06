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
struct bstr {scalar_t__ len; int /*<<< orphan*/ * start; } ;

/* Variables and functions */
 scalar_t__ mp_isspace (int /*<<< orphan*/ ) ; 

struct bstr bstr_lstrip(struct bstr str)
{
    while (str.len && mp_isspace(*str.start)) {
        str.start++;
        str.len--;
    }
    return str;
}