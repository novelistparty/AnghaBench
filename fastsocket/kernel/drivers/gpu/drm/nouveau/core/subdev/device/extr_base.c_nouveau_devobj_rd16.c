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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u16 ;
struct nouveau_object {int /*<<< orphan*/  engine; } ;

/* Variables and functions */
 int /*<<< orphan*/  nv_rd16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u16
nouveau_devobj_rd16(struct nouveau_object *object, u64 addr)
{
	return nv_rd16(object->engine, addr);
}