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
struct snd_emu10k1 {int dummy; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 scalar_t__ EMUPAGESIZE ; 
 int UNIT_PAGES ; 
 int /*<<< orphan*/  __set_ptb_entry (struct snd_emu10k1*,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void set_ptb_entry(struct snd_emu10k1 *emu, int page, dma_addr_t addr)
{
	int i;
	page *= UNIT_PAGES;
	for (i = 0; i < UNIT_PAGES; i++, page++) {
		__set_ptb_entry(emu, page, addr);
		addr += EMUPAGESIZE;
	}
}