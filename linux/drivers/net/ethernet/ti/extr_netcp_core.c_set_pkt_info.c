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
typedef  int /*<<< orphan*/  u32 ;
struct knav_dma_desc {void* next_desc; void* buff; void* buff_len; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 void* cpu_to_le32 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void set_pkt_info(dma_addr_t buff, u32 buff_len, u32 ndesc,
			 struct knav_dma_desc *desc)
{
	desc->buff_len = cpu_to_le32(buff_len);
	desc->buff = cpu_to_le32(buff);
	desc->next_desc = cpu_to_le32(ndesc);
}