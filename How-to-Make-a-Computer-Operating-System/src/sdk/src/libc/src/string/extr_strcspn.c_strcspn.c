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

/* Variables and functions */
 int strlen (char const*) ; 

size_t strcspn( const char* s, const char* reject ) {
    size_t l = 0;
    int a = 1;
    int i;
    int al = strlen( reject );

    while ( ( a ) && ( *s ) ) {
        for ( i = 0; ( a ) && ( i < al ); i++ ) {
            if ( *s == reject[ i ] ) {
                a = 0;
            }
        }

        if ( a ) {
            l++;
        }

        s++;
    }

    return l;
}