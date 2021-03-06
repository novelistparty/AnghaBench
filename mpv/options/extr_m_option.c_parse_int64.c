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
struct mp_log {int dummy; } ;
struct bstr {int dummy; } ;
typedef  int /*<<< orphan*/  m_option_t ;
typedef  long long int64_t ;

/* Variables and functions */
 int parse_longlong (struct mp_log*,int /*<<< orphan*/  const*,struct bstr,struct bstr,long long*) ; 

__attribute__((used)) static int parse_int64(struct mp_log *log, const m_option_t *opt,
                       struct bstr name, struct bstr param, void *dst)
{
    long long tmp;
    int r = parse_longlong(log, opt, name, param, &tmp);
    if (r >= 0 && dst)
        *(int64_t *)dst = tmp;
    return r;
}