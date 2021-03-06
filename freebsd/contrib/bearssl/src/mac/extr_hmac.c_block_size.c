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
struct TYPE_3__ {int desc; } ;
typedef  TYPE_1__ br_hash_class ;

/* Variables and functions */
 unsigned int BR_HASHDESC_LBLEN_MASK ; 
 int BR_HASHDESC_LBLEN_OFF ; 

__attribute__((used)) static inline size_t
block_size(const br_hash_class *dig)
{
	unsigned ls;
	
	ls = (unsigned)(dig->desc >> BR_HASHDESC_LBLEN_OFF)
		& BR_HASHDESC_LBLEN_MASK;
	return (size_t)1 << ls;
}