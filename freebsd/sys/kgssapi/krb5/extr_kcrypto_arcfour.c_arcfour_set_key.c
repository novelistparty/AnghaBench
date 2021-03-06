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
struct krb5_key_state {void* ks_key; } ;

/* Variables and functions */
 int /*<<< orphan*/  bcopy (void const*,void*,int) ; 

__attribute__((used)) static void
arcfour_set_key(struct krb5_key_state *ks, const void *in)
{
	void *kp = ks->ks_key;

	if (kp != in)
		bcopy(in, kp, 16);
}