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
struct sja1105_avb_params_entry {int /*<<< orphan*/  srcmeta; int /*<<< orphan*/  destmeta; } ;
typedef  enum packing_op { ____Placeholder_packing_op } packing_op ;

/* Variables and functions */
 size_t SJA1105ET_SIZE_AVB_PARAMS_ENTRY ; 
 int /*<<< orphan*/  sja1105_packing (void*,int /*<<< orphan*/ *,int,int,size_t const,int) ; 

__attribute__((used)) static size_t sja1105et_avb_params_entry_packing(void *buf, void *entry_ptr,
						 enum packing_op op)
{
	const size_t size = SJA1105ET_SIZE_AVB_PARAMS_ENTRY;
	struct sja1105_avb_params_entry *entry = entry_ptr;

	sja1105_packing(buf, &entry->destmeta, 95, 48, size, op);
	sja1105_packing(buf, &entry->srcmeta,  47,  0, size, op);
	return size;
}