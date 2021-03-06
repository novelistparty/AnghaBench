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

/* Variables and functions */
 int /*<<< orphan*/  FIFODATA ; 
 int /*<<< orphan*/  nsp_mmio_multi_read_4 (unsigned int,int /*<<< orphan*/ ,void*,unsigned long) ; 

__attribute__((used)) static inline void nsp_mmio_fifo32_read(unsigned int   base,
					void          *buf,
					unsigned long  count)
{
	//nsp_dbg(NSP_DEBUG_DATA_IO, "buf=0x%p, count=0x%lx*4", buf, count);
	nsp_mmio_multi_read_4(base, FIFODATA, buf, count);
}