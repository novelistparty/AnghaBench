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
struct rbsp {int dummy; } ;

/* Variables and functions */
 int rbsp_write_bits (struct rbsp*,int,unsigned int) ; 

__attribute__((used)) static int __rbsp_write_bits(struct rbsp *rbsp, int n, unsigned int *value)
{
	return rbsp_write_bits(rbsp, n, *value);
}