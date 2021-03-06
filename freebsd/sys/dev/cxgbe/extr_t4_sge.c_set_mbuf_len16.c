#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_3__ {int /*<<< orphan*/ * eight; } ;
struct TYPE_4__ {TYPE_1__ PH_loc; } ;
struct mbuf {TYPE_2__ m_pkthdr; } ;

/* Variables and functions */
 int /*<<< orphan*/  M_ASSERTPKTHDR (struct mbuf*) ; 

__attribute__((used)) static inline void
set_mbuf_len16(struct mbuf *m, uint8_t len16)
{

	M_ASSERTPKTHDR(m);
	m->m_pkthdr.PH_loc.eight[0] = len16;
}