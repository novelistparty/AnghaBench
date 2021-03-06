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
typedef  char WCHAR ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ is_alpha (char) ; 
 scalar_t__ is_num (char) ; 

__attribute__((used)) static inline BOOL is_unreserved(WCHAR val) {
    return (is_alpha(val) || is_num(val) || val == '-' || val == '.' ||
            val == '_' || val == '~');
}