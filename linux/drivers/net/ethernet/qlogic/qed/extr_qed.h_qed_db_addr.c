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
typedef  int u32 ;

/* Variables and functions */
 int /*<<< orphan*/  DB_LEGACY_ADDR_DEMS ; 
 int FIELD_VALUE (int /*<<< orphan*/ ,int) ; 
 int QED_PF_DEMS_SIZE ; 

__attribute__((used)) static inline u32 qed_db_addr(u32 cid, u32 DEMS)
{
	u32 db_addr = FIELD_VALUE(DB_LEGACY_ADDR_DEMS, DEMS) |
		      (cid * QED_PF_DEMS_SIZE);

	return db_addr;
}