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
struct SN_env {int c; int lb; int l; } ;

/* Variables and functions */
 int r_mark_regions (struct SN_env*) ; 
 int r_postlude (struct SN_env*) ; 
 int r_prelude (struct SN_env*) ; 
 int r_standard_suffix (struct SN_env*) ; 

extern int german_UTF_8_stem(struct SN_env * z) { /* forwardmode */
    {   int c1 = z->c; /* do, line 134 */
        {   int ret = r_prelude(z); /* call prelude, line 134 */
            if (ret == 0) goto lab0;
            if (ret < 0) return ret;
        }
    lab0:
        z->c = c1;
    }
    {   int c2 = z->c; /* do, line 135 */
        {   int ret = r_mark_regions(z); /* call mark_regions, line 135 */
            if (ret == 0) goto lab1;
            if (ret < 0) return ret;
        }
    lab1:
        z->c = c2;
    }
    z->lb = z->c; z->c = z->l; /* backwards, line 136 */

    /* do, line 137 */
    {   int ret = r_standard_suffix(z); /* call standard_suffix, line 137 */
        if (ret == 0) goto lab2;
        if (ret < 0) return ret;
    }
lab2:
    z->c = z->lb;
    {   int c3 = z->c; /* do, line 138 */
        {   int ret = r_postlude(z); /* call postlude, line 138 */
            if (ret == 0) goto lab3;
            if (ret < 0) return ret;
        }
    lab3:
        z->c = c3;
    }
    return 1;
}