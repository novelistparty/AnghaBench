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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;

/* Variables and functions */
 scalar_t__ ParseVarLenInteger (int /*<<< orphan*/  const*,int,int*,int*) ; 

__attribute__((used)) static inline bool AACCookieTagLen( uint64_t *p_tag_len, const uint8_t *p, uint64_t *p_offset, uint64_t i_size )
{
    uint32_t i_int_size;

    if( ParseVarLenInteger( p + *p_offset, i_size - *p_offset, p_tag_len, &i_int_size ))
        return false;

    *p_offset += i_int_size;

    return true;
}