#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {size_t n; scalar_t__* p; } ;
typedef  TYPE_1__ mbedtls_mpi ;

/* Variables and functions */

__attribute__((used)) static inline size_t word_length(const mbedtls_mpi *mpi)
{
    for(size_t i = mpi->n; i > 0; i--) {
        if( mpi->p[i - 1] != 0 ) {
            return i;
        }
    }
    return 0;
}