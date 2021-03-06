#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mbuf {int dummy; } ;
struct krb5_key_state {TYPE_1__* ks_class; } ;
struct TYPE_2__ {int /*<<< orphan*/  (* ec_decrypt ) (struct krb5_key_state const*,struct mbuf*,size_t,size_t,void*,size_t) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (struct krb5_key_state const*,struct mbuf*,size_t,size_t,void*,size_t) ; 

__attribute__((used)) static __inline void
krb5_decrypt(const struct krb5_key_state *ks, struct mbuf *inout,
    size_t skip, size_t len, void *ivec, size_t ivlen)
{

	ks->ks_class->ec_decrypt(ks, inout, skip, len, ivec, ivlen);
}