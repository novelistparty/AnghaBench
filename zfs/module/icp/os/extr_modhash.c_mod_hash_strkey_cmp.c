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
typedef  scalar_t__ mod_hash_key_t ;

/* Variables and functions */
 int strcmp (char*,char*) ; 

int
mod_hash_strkey_cmp(mod_hash_key_t key1, mod_hash_key_t key2)
{
	return (strcmp((char *)key1, (char *)key2));
}