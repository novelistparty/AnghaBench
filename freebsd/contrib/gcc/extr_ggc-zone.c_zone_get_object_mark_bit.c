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
typedef  int /*<<< orphan*/  mark_type ;

/* Variables and functions */
 size_t BYTES_PER_MARK_BIT ; 

__attribute__((used)) static inline unsigned int
zone_get_object_mark_bit (const void *object)
{
  return (((size_t) object / BYTES_PER_MARK_BIT)
	  % (8 * sizeof (mark_type)));
}