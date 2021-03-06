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
struct SN_env {int* I; int l; int c; } ;

/* Variables and functions */
 int /*<<< orphan*/  g_v ; 
 int in_grouping (struct SN_env*,int /*<<< orphan*/ ,int,int,int) ; 
 scalar_t__ out_grouping (struct SN_env*,int /*<<< orphan*/ ,int,int,int) ; 

__attribute__((used)) static int r_mark_regions(struct SN_env * z) { /* forwardmode */
    z->I[0] = z->l; /* $p1 = <integer expression>, line 28 */
    {   int c_test1 = z->c; /* test, line 30 */
        {   int ret = z->c + 3; /* hop, line 30 */
            if (0 > ret || ret > z->l) return 0;
            z->c = ret;
        }
        z->I[1] = z->c; /* setmark x, line 30 */
        z->c = c_test1;
    }
    if (out_grouping(z, g_v, 97, 248, 1) < 0) return 0; /* goto */ /* grouping v, line 31 */
    {    /* gopast */ /* non v, line 31 */
        int ret = in_grouping(z, g_v, 97, 248, 1);
        if (ret < 0) return 0;
        z->c += ret;
    }
    z->I[0] = z->c; /* setmark p1, line 31 */
    /* try, line 32 */
    if (!(z->I[0] < z->I[1])) goto lab0; /* $(<integer expression> < <integer expression>), line 32 */
    z->I[0] = z->I[1]; /* $p1 = <integer expression>, line 32 */
lab0:
    return 1;
}